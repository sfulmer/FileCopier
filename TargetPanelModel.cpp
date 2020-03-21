#include "TargetPanelModel.h"

using namespace net::draconia::FileCopier::model;

Properties TargetPanelModel::prefixWithDividerKey(const Properties &refProperties)
{
    return(refProperties);
}

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

Properties TargetPanelModel::pullSettingsToProperties()
{
    Properties objProperties;

    objProperties.add(Property("Target.Filename", getFilename()));
    objProperties.add(Property("Target.Path", getPath()));

    return(objProperties);
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

void TargetPanelModel::setUp(const Properties &refProperties)
{
    for(Property objProperty : refProperties)
        {
        QString sUpperKey = objProperty.getKey().toUpper();

        if(sUpperKey == "FILENAME")
            setFilename(objProperty.getValue());
        else if(sUpperKey == "PATH")
            setPath(objProperty.getValue());
        }
}
