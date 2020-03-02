#include <QFileInfo>
#include "SourcePanelModel.h"

using namespace net::draconia::FileCopier::model;

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

void SourcePanelModel::setSourceFile(const QString sPath)
{
    msSourceFile = sPath;

    setChanged();
    notifyObservers("SourceFile");
}
