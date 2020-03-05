#include "FileCopierController.h"
#include <fstream>
#include <iostream>
#include "ProcessModel.h"
#include <QCoreApplication>
#include <QDir>
#include <QFileInfo>

using net::draconia::FileCopier::FileCopierController;
using namespace net::draconia::FileCopier::model;
using namespace std;

void ProcessModel::Status::setText(const QString &sText)
{
    msText = sText;
}

ProcessModel::Status::Status()
{ }

ProcessModel::Status::Status(const QString &sText)
    : msText(sText)
{ }

ProcessModel::Status::Status(const ProcessModel::Status &refCopy)
    : msText(refCopy.getText())
{ }

const QString &ProcessModel::Status::getText() const
{
    return(msText);
}

bool ProcessModel::Status::operator==(const Status &refOther) const
{
    return(getText() == refOther.getText());
}

bool ProcessModel::Status::operator!=(const Status &refOther) const
{
    return(!operator==(refOther));
}

ProcessModel::Status &ProcessModel::Status::operator=(const Status &refCopy)
{
    setText(refCopy.getText());

    return(*this);
}

const ProcessModel::Status ProcessModel::Status::DONE("Done");
const ProcessModel::Status ProcessModel::Status::MOVING("Moving");
const ProcessModel::Status ProcessModel::Status::PAUSED("Paused");
const ProcessModel::Status ProcessModel::Status::SETUP("Setup");
const ProcessModel::Status ProcessModel::Status::STALLED("Stalled");

qint64 ProcessModel::calculateTotalBytesToMove() const
{
    qint64 iTotal = 0L;

    for(QString sFile : getFiles())
        iTotal += QFileInfo(sFile).size();

    return(iTotal);
}

char *ProcessModel::getBuffer()
{
    return(mcBuffer);
}

int ProcessModel::getBufferReadSize() const
{
    return(miBufferReadSize);
}

int ProcessModel::getBufferSize() const
{
    return(miBufferSize);
}

QList<QString> &ProcessModel::getFiles() const
{
    return(const_cast<QList<QString> &>(mLstFiles));
}

ifstream &ProcessModel::getInputFile()
{
    return(mObjIn);
}

ofstream &ProcessModel::getOutputFile()
{
    return(mObjOut);
}

bool ProcessModel::isDirectoryEmptyForFile(const QString &sFile) const
{
    QDir dir(QFileInfo(sFile).path());

    return(dir.isEmpty());
}

void ProcessModel::moveFile(const QString sSource, const QString sTarget)
{
    if(!getInputFile().is_open())
        {
        getInputFile().open(sSource.toStdString(), ios_base::in | ios_base::binary);
        getInputFile().seekg(getCurrentPosition());

        if(!getOutputFile().is_open())
            getOutputFile().open(sTarget.toStdString(), ios_base::ate | ios_base::binary);
        }
    else
        getOutputFile().open(sTarget.toStdString(), ios_base::out | ios_base::binary);

    QCoreApplication::processEvents();

    // Write the current buffer before reading more
    if(isMoving() && getOutputFile() && (getBufferReadSize() > 0))
        {
        getOutputFile().write(getBuffer(), getBufferReadSize());

        setCurrentBytesMoved(getCurrentBytesMoved() + getBufferReadSize());
        }

     while((!getInputFile().eof()) && (!getInputFile()))
        {
        if(isMoving())
            if(getInputFile())
                {
                setBufferReadSize(getInputFile().read(getBuffer(), getBufferSize()).gcount());
                setCurrentPosition(getInputFile().tellg());

                if(((getBufferReadSize() < getBufferSize()) && (!getInputFile().eof())) || (!getInputFile()))
                    {
                    setStatus(Status::STALLED);

                    setCurrentPosition(getCurrentPosition() - getBufferReadSize());
                    setBufferReadSize(0);
                    }
                }

        QCoreApplication::processEvents();

        if(isMoving())
            if(getOutputFile())
                {
                getOutputFile().write(getBuffer(), getBufferReadSize());

                setCurrentBytesMoved(getCurrentBytesMoved() + getBufferReadSize());
                }
        }

     QCoreApplication::processEvents();

     if(isMoving())
        if(getInputFile().eof() && getInputFile())
           {
           getInputFile().close();

           getOutputFile().flush();
           getOutputFile().close();

           setCurrentPosition(0);
           }
}

void ProcessModel::removeCurrentDirectory()
{
    QDir parent(QFileInfo(getCurrentFile()).path());

    parent.cdUp();
    parent.rmdir(QFileInfo(QFileInfo(getCurrentFile()).path()).fileName());

    setChanged();
    notifyObservers("Files");
}

void ProcessModel::removeCurrentFile()
{
    QFile(getCurrentFile()).remove();

    setChanged();
    notifyObservers("Files");
}

void ProcessModel::setBufferReadSize(const int iBufferReadSize)
{
    miBufferReadSize = iBufferReadSize;
}

void ProcessModel::setBufferSize(const int iBufferSize)
{
    miBufferSize = iBufferSize;
}

void ProcessModel::setCurrentBytesMoved(const qint64 iCurrentBytesMoved)
{
    miCurrentBytesMoved = iCurrentBytesMoved;

    setChanged();
    notifyObservers("CurrentBytesMoved");
}

void ProcessModel::setCurrentFile(const QString &sFile)
{
    msCurrentFile = sFile;

    setChanged();
    notifyObservers("CurrentFile");
}

void ProcessModel::setCurrentPosition(const long &lPosition)
{
    mlCurrentPosition = lPosition;

    setChanged();
    notifyObservers("CurrentPosition");
}

void ProcessModel::setStatus(const Status &refStatus)
{
    mObjStatus = refStatus;

    setChanged();
    notifyObservers("Status");
}

void ProcessModel::setTotalBytesToMove(const qint64 iTotalBytesToMove)
{
    if(iTotalBytesToMove <= 0)
        miTotalBytesToMove = calculateTotalBytesToMove();
    else
        miTotalBytesToMove = iTotalBytesToMove;

    setChanged();
    notifyObservers("TotalBytesToMove");
}

ProcessModel::ProcessModel(FileCopierController &refController)
    :   Observable()
    ,   mRefController(refController)
    ,   miBufferReadSize(0), miBufferSize(1024)
    ,   mlCurrentPosition(-1)
    ,   miTotalBytesToMove(0)
    ,   mObjStatus(const_cast<ProcessModel::Status &>(Status::SETUP))
{ }

ProcessModel::ProcessModel(const ProcessModel &refCopy)
    :   Observable(refCopy)
    ,   mRefController(refCopy.getController())
    ,   miBufferReadSize(refCopy.getBufferReadSize())
    ,   miBufferSize(refCopy.getBufferSize())
    ,   mlCurrentPosition(refCopy.getCurrentPosition())
    ,   miTotalBytesToMove(0)
    ,   msCurrentFile(refCopy.getCurrentFile())
    ,   mObjStatus(refCopy.getStatus())
{ }

void ProcessModel::addFile(const QString &sFile)
{
    getFiles().append(sFile);

    setChanged();
    notifyObservers("FilesToMove");
}

void ProcessModel::exit()
{
    getController().exit();
}

FileCopierController &ProcessModel::getController() const
{
    return(const_cast<FileCopierController &>(mRefController));
}

qint64 ProcessModel::getCurrentBytesMoved() const
{
    return(miCurrentBytesMoved);
}

QString &ProcessModel::getCurrentFile() const
{
    return(const_cast<QString &>(msCurrentFile));
}

long &ProcessModel::getCurrentPosition() const
{
    return(const_cast<long &>(mlCurrentPosition));
}

const QList<QString> &ProcessModel::getFilesToMove() const
{
    return(getFiles());
}

ProcessModel::Status &ProcessModel::getStatus() const
{
    return(const_cast<Status &>(mObjStatus));
}

qint64 ProcessModel::getTotalBytesToMove()
{
    if(miTotalBytesToMove <= 0)
        miTotalBytesToMove = calculateTotalBytesToMove();

    return(miTotalBytesToMove);
}

bool ProcessModel::isDone() const
{
    return(getStatus() == Status::DONE);
}

bool ProcessModel::isMoving() const
{
    return(getStatus() == Status::MOVING);
}

bool ProcessModel::isPaused() const
{
    return(getStatus() == Status::PAUSED);
}

bool ProcessModel::isSetup() const
{
    return(getStatus() == Status::SETUP);
}

bool ProcessModel::isStalled() const
{
    return(getStatus() == Status::STALLED);
}

void ProcessModel::pause()
{
    setStatus(Status::PAUSED);
}

void ProcessModel::resume()
{
    // Changes the displayed Status
    setStatus(Status::MOVING);

    // Iterates the Files
    for(QString sFile : getFilesToMove())
        {
        QCoreApplication::processEvents();

        // Get the File Info
        QFileInfo fileInfo(sFile);

        // Calculate the target file and path
        QString sTargetFileAndPath = getController().getSetupModel().getTargetPanelModel().getPath() + fileInfo.fileName();

        // Move the file from the source filename and path to the target filename and path
        moveFile(sFile, sTargetFileAndPath);

        QCoreApplication::processEvents();

        if(isMoving() && (!(getInputFile().is_open())))
            {
            removeCurrentFile();

            QCoreApplication::processEvents();

            if(QDir(getCurrentFile()).isEmpty())
                removeCurrentDirectory();

            mLstFiles.removeOne(sFile);
            }
        }

    QCoreApplication::processEvents();

    if(getFilesToMove().isEmpty())
        setStatus(Status::DONE);
}

void ProcessModel::setFilesToMove(const QList<QString> &lstFiles)
{
    getFiles().clear();
    getFiles().append(lstFiles);

    setChanged();
    notifyObservers("FilesToMove");
}

void ProcessModel::start()
{
    // Sets up the Progress Bar
    setTotalBytesToMove(0);

    // Sets the initial File Position
    setCurrentPosition(0);

    // The same events will happen with resume from here on out
    resume();
}
