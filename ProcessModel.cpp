#include "ProcessModel.h"

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

const static ProcessModel::Status COPYING("Copying");
const static ProcessModel::Status DONE("Done");
const static ProcessModel::Status PAUSED("Paused");
const static ProcessModel::Status SETUP("Setup");
const static ProcessModel::Status STALLED("Stalled");

QMap<QDir, QList<QFile>> &ProcessModel::getFiles() const
{
    return(const_cast<QMap<QDir, QList<QFile>> &>(mMapFiles));
}

ProcessModel::ProcessModel()
    :   Observable()
    ,   mlCurrentPosition(-1)
    ,   mObjStatus(Status::SETUP)
{ }

ProcessModel::ProcessModel(const QDir &dirCurrent)
    :   Observable()
    ,   mlCurrentPosition(-1)
    ,   mDirCurrent(dirCurrent)
    ,   mObjStatus(Status::SETUP)
{
    // TODO Iterate the files/folders in dirCurrent
}


ProcessModel::ProcessModel(const QFile &objFile)
    :   Observable()
    ,   mlCurrentPosition(-1)
    ,   mObjCurrentFile(objFile.fileName())
    ,   mObjStatus(Status::SETUP)
{ }

ProcessModel::ProcessModel(const QFileInfo &objFile)
    :   Observable()
    ,   mlCurrentPosition(-1)
    ,   mObjCurrentFile(objFile.fileName())
    ,   mObjStatus(Status::SETUP)
{ }

ProcessModel::ProcessModel(const QString &sFilename)
    :   Observable()
    ,   mlCurrentPosition(-1)
    ,   mObjCurrentFile(sFilename)
    ,   mObjStatus(Status::SETUP)
{ }

ProcessModel::ProcessModel(const ProcessModel &refCopy)
    :   Observable(refCopy)
    ,   mlCurrentPosition(refCopy.getCurrentPosition())
    ,   mDirCurrent(refCopy.getCurrentDirectory())
    ,   mObjCurrentFile(refCopy.getCurrentFile().fileName())
    ,   mObjStatus(refCopy.getStatus())
{ }

void ProcessModel::addDirectory(const QDir &refDirectory, const QList<QFile> &lstFiles)
{
    getFiles().insert(refDirectory, lstFiles);

    setChanged();
    notifyObservers("Directory");
}

QDir &ProcessModel::getCurrentDirectory() const
{
    return(const_cast<QDir &>(mDirCurrent));
}

QFile &ProcessModel::getCurrentFile() const
{
    return(const_cast<QFile &>(mObjCurrentFile));
}

long &ProcessModel::getCurrentPosition() const
{
    return(const_cast<long &>(mlCurrentPosition));
}

const QList<QFile> &ProcessModel::getFilesForDirectory(const QDir &refDirectory) const
{
    return(getFiles()[refDirectory]);
}

ProcessModel::Status &ProcessModel::getStatus() const
{
    return(const_cast<Status &>(mObjStatus));
}

void ProcessModel::pause()
{
        //TODO Do stuff to set status to PAUSE
}

void ProcessModel::removeDirecotry(const QDir &refDirectory)
{
    getFiles().remove(refDirectory);

    // TODO Do something to delete from the file system
}

void ProcessModel::removeFileUnderDirectory(const QDir &refDirectory, const QFile &refFile)
{
    getFiles()[refDirectory].removeOne(refFile);

    //TODO Do something to remove from the file system
}

void ProcessModel::removeFileUnderDirectory(const QDir &refDirectory, const QString &sFile)
{
    removeFileUnderDirectory(refDirectory, QFile(sFile));
}

void ProcessModel::setCurrentDirectory(const QDir &refDirectory)
{
    mDirCurrent = refDirectory;

    setChanged();
    notifyObservers("CurrentDirectory");
}

void ProcessModel::setCurrentFile(const QFile &objFile)
{
    setCurrentFile(objFile.fileName());
}

void ProcessModel::setCurrentFile(const QString &sFile)
{
    mObjCurrentFile = QFile(sFile);

    setChanged();
    notifyObservers("CurrentFile");
}

void ProcessModel::setCurrentPosition(const long &lPosition)
{
    mlCurrentPosition = lPosition;

    setChanged();
    notifyObservers("CurrentPosition");
}

void ProcessModel::setFilesForDirectory(const QDir &refDirectory, const QList<QFile> &lstFiles)
{
    getFiles()[refDirectory] = lstFiles;

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
