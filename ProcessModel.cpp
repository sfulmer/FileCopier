#include "ProcessModel.h"

using net::draconia::FileCopier::FileCopierController;
using namespace net::draconia::FileCopier::model;

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

const ProcessModel::Status ProcessModel::Status::COPYING("Copying");
const ProcessModel::Status ProcessModel::Status::DONE("Done");
const ProcessModel::Status ProcessModel::Status::PAUSED("Paused");
const ProcessModel::Status ProcessModel::Status::SETUP("Setup");
const ProcessModel::Status ProcessModel::Status::STALLED("Stalled");

QMap<QString, QList<QString>> &ProcessModel::getFiles() const
{
    return(const_cast<QMap<QString, QList<QString>> &>(mMapFiles));
}

ProcessModel::ProcessModel(FileCopierController &refController)
    :   Observable()
    ,   mRefController(refController)
    ,   mlCurrentPosition(-1)
    ,   mObjStatus(Status::SETUP)
{ }

ProcessModel::ProcessModel(FileCopierController &refController, const QString &sFilename)
    :   Observable()
    ,   mRefController(refController)
    ,   mlCurrentPosition(-1)
    ,   msCurrentFile(sFilename)
    ,   mObjStatus(Status::SETUP)
{
    //TODO Put code to extract the directory/path from the filename string when viewed as a file object
}

ProcessModel::ProcessModel(const ProcessModel &refCopy)
    :   Observable(refCopy)
    ,   mRefController(refCopy.getController())
    ,   mlCurrentPosition(refCopy.getCurrentPosition())
    ,   msCurrentDirectory(refCopy.getCurrentDirectory())
    ,   msCurrentFile(refCopy.getCurrentFile())
    ,   mObjStatus(refCopy.getStatus())
{ }

void ProcessModel::addDirectory(const QString &sDirectory, const QList<QString> &lstFiles)
{
    getFiles().insert(sDirectory, lstFiles);

    setChanged();
    notifyObservers("Directory");
}

void ProcessModel::exit()
{
    //TODO Put code in here
}

FileCopierController &ProcessModel::getController() const
{
    return(const_cast<FileCopierController &>(mRefController));
}

QString &ProcessModel::getCurrentDirectory() const
{
    return(const_cast<QString &>(msCurrentDirectory));
}

QString &ProcessModel::getCurrentFile() const
{
    return(const_cast<QString &>(msCurrentFile));
}

long &ProcessModel::getCurrentPosition() const
{
    return(const_cast<long &>(mlCurrentPosition));
}

const QList<QString> &ProcessModel::getFilesForDirectory(const QString &sDirectory) const
{
    return(getFiles()[sDirectory]);
}

ProcessModel::Status &ProcessModel::getStatus() const
{
    return(const_cast<Status &>(mObjStatus));
}

void ProcessModel::pause()
{
        //TODO Do stuff to set status to PAUSE
}

void ProcessModel::removeDirecotry(const QString &sDirectory)
{
    getFiles().remove(sDirectory);

    // TODO Do something to delete from the file system
}

void ProcessModel::removeFileUnderDirectory(const QString &sDirectory, const QString &sFile)
{
    getFiles()[sDirectory].removeOne(sFile);

    //TODO Do something to remove from the file system
}

void ProcessModel::setCurrentDirectory(const QString &sDirectory)
{
    msCurrentDirectory = sDirectory;

    setChanged();
    notifyObservers("CurrentDirectory");
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

void ProcessModel::setFilesForDirectory(const QString &sDirectory, const QList<QString> &lstFiles)
{
    getFiles()[sDirectory] = lstFiles;

    setChanged();
    notifyObservers("Directory");
}

void ProcessModel::setStatus(const Status &refStatus)
{
    mObjStatus = refStatus;

    setChanged();
    notifyObservers("Status");
}

void ProcessModel::startCopying()
{
    // TODO Do something to set status to COPYING
}
