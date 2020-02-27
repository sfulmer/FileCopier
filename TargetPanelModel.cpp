#include "TargetPanelModel.h"

using namespace net::draconia::FileCopier::model;

TargetPanelModel::TargetPanelModel()
    :   Observable()
{ }

TargetPanelModel::TargetPanelModel(const QString &sPath, const QString &sFilename)
    :   Observable()
    ,   msTargetFilename(sFilename)
    ,   msTargetPath(sPath)
{ }

TargetPanelModel::TargetPanelModel(const TargetPanelModel &refCopy)
    :   Observable(refCopy)
    ,   msTargetFilename((refCopy.getFilename()))
    ,   msTargetPath((refCopy.getPath()))
{ }

QString &TargetPanelModel::getFilename() const
{
    return(const_cast<QString &>(msTargetFilename));
}

QString &TargetPanelModel::getPath() const
{
    return(const_cast<QString &>(msTargetPath));
}

void TargetPanelModel::setFilename(const QString &sFilename)
{
    msTargetFilename = sFilename;

    setChanged();
    notifyObservers("Filename");
}

void TargetPanelModel::setPath(const QString &sPath)
{
    msTargetPath = sPath;

    setChanged();
    notifyObservers("Path");
}
