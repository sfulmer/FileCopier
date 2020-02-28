#include "SetupModel.h"

using net::draconia::FileCopier::FileCopierController;
using namespace net::draconia::FileCopier::model;

SetupModel::SetupModel(FileCopierController &refController)
    :   Observable()
    ,   mbRestartFromLastPosition(true)
    ,   mRefController(refController)
{ }

SetupModel::SetupModel(FileCopierController &refController, const SourcePanelModel &refSourceModel, const TargetPanelModel &refTargetModel)
    :   Observable()
    ,   mbRestartFromLastPosition(true)
    ,   mRefController(refController)
    ,   mObjSourcePanelModel(refSourceModel)
    ,   mObjTargetPanelModel(refTargetModel)
{ }

SetupModel::SetupModel(const SetupModel &refCopy)
    :   Observable(refCopy)
    ,   mbRestartFromLastPosition(refCopy.getRestartFromLastPosition())
    ,   mRefController(refCopy.getController())
    ,   mObjSourcePanelModel(refCopy.getSourcePanelModel())
    ,   mObjTargetPanelModel(refCopy.getTargetPanelModel())
{ }

FileCopierController &SetupModel::getController() const
{
    return(const_cast<FileCopierController &>(mRefController));
}

bool SetupModel::getRestartFromLastPosition() const
{
    return(mbRestartFromLastPosition);
}

SourcePanelModel &SetupModel::getSourcePanelModel() const
{
    return(const_cast<SourcePanelModel &>(mObjSourcePanelModel));
}

TargetPanelModel &SetupModel::getTargetPanelModel() const
{
    return(const_cast<TargetPanelModel &>(mObjTargetPanelModel));
}

void SetupModel::setRestartFromLastPosition(const bool bRestartFromLastPosition)
{
    mbRestartFromLastPosition = bRestartFromLastPosition;

    setChanged();
    notifyObservers("RestartFromLastPosition");
}
