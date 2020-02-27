#include "FileCopierModel.h"

using namespace net::draconia::FileCopier::model;

FileCopierModel::FileCopierModel()
    :   Observable()
    ,   mbRestartFromLastPosition(true)
    ,   mObjStatus(Status::SETUP)
{ }

FileCopierModel::FileCopierModel(const SourcePanelModel &refSourceModel, const TargetPanelModel &refTargetModel)
    :   Observable()
    ,   mbRestartFromLastPosition(true)
    ,   mObjSourcePanelModel(refSourceModel)
    ,   mObjStatus(Status::SETUP)
    ,   mObjTargetPanelModel(refTargetModel)
{ }

FileCopierModel::FileCopierModel(const FileCopierModel &refCopy)
    :   Observable(refCopy)
    ,   mbRestartFromLastPosition(refCopy.getRestartFromLastPosition())
    ,   mObjSourcePanelModel(refCopy.getSourcePanelModel())
    ,   mObjStatus(refCopy.getStatus())
    ,   mObjTargetPanelModel(refCopy.getTargetPanelModel())
{ }

bool FileCopierModel::getRestartFromLastPosition() const
{
    return(mbRestartFromLastPosition);
}

SourcePanelModel &FileCopierModel::getSourcePanelModel() const
{
    return(const_cast<SourcePanelModel &>(mObjSourcePanelModel));
}

FileCopierModel::Status &FileCopierModel::getStatus() const
{
    return(const_cast<FileCopierModel::Status &>(mObjStatus));
}

TargetPanelModel &FileCopierModel::getTargetPanelModel() const
{
    return(const_cast<TargetPanelModel &>(mObjTargetPanelModel));
}

void FileCopierModel::setRestartFromLastPosition(const bool bRestartFromLastPosition)
{
    mbRestartFromLastPosition = bRestartFromLastPosition;

    setChanged();
    notifyObservers("RestartFromLastPosition");
}
void FileCopierModel::setStatus(const Status &refStatus)
{
    mObjStatus = refStatus;

    setChanged();
    notifyObservers("Status");
}
