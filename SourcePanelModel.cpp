#include <QFileInfo>
#include "SourcePanelModel.h"

using namespace net::draconia::FileCopier::model;

Properties SourcePanelModel::prefixWithDividerKey(const Properties &refProperties)
{
    return(refProperties);
}

void SourcePanelModel::setDirectory(const bool bDirectory)
{
    mbDirectory = bDirectory;

    setChanged();
    notifyObservers("Directory");
}

SourcePanelModel::SourcePanelModel()
    :   Observable()
    ,   mbDirectory(false)
{ }

SourcePanelModel::SourcePanelModel(const QString &sPath)
    :   Observable()
    ,   mbDirectory(QFileInfo(sPath).isDir())
    ,   msSourceFile(sPath)
{ }

SourcePanelModel::SourcePanelModel(const SourcePanelModel &refCopy)
    :   Observable(refCopy)
    ,   mbDirectory(refCopy.isDirectory())
    ,   msSourceFile(refCopy.getSourceFile())
{ }

QString &SourcePanelModel::getSourceFile() const
{
    return(const_cast<QString &>(msSourceFile));
}

bool SourcePanelModel::isDirectory() const
{
    return(mbDirectory);
}

Properties SourcePanelModel::pullSettingsToProperties()
{
    Properties objProperties;

    objProperties.add(Property("Source.SourceFile", getSourceFile()));

    return(objProperties);
}

void SourcePanelModel::setSourceFile(const QString sPath)
{
    msSourceFile = sPath;

    setChanged();
    notifyObservers("SourceFile");
}

void SourcePanelModel::setUp(const Properties &refProperties)
{
    for(Property objProperty : refProperties)
        if(objProperty.getKey().toUpper() == "SOURCEFILE")
            setSourceFile(objProperty.getValue());
}
