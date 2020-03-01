#include "SetupModel.h"

using net::draconia::FileCopier::FileCopierController;
using namespace net::draconia::FileCopier::model;

SetupModel::SetupModel(FileCopierController &refController)
    :   Observable()
    ,   mbResumeFromLastPosition(true)
    ,   mRefController(refController)
{ }

SetupModel::SetupModel(FileCopierController &refController, const SourcePanelModel &refSourceModel, const TargetPanelModel &refTargetModel)
    :   Observable()
    ,   mbResumeFromLastPosition(true)
    ,   mRefController(refController)
    ,   mObjSourcePanelModel(refSourceModel)
    ,   mObjTargetPanelModel(refTargetModel)
{ }

SetupModel::SetupModel(const SetupModel &refCopy)
    :   Observable(refCopy)
    ,   mbResumeFromLastPosition(refCopy.getResumeFromLastPosition())
    ,   mRefController(refCopy.getController())
    ,   mObjSourcePanelModel(refCopy.getSourcePanelModel())
    ,   mObjTargetPanelModel(refCopy.getTargetPanelModel())
{ }

FileCopierController &SetupModel::getController() const
{
    return(const_cast<FileCopierController &>(mRefController));
}

bool SetupModel::getResumeFromLastPosition() const
{
    return(mbResumeFromLastPosition);
}

SourcePanelModel &SetupModel::getSourcePanelModel() const
{
    return(const_cast<SourcePanelModel &>(mObjSourcePanelModel));
}

TargetPanelModel &SetupModel::getTargetPanelModel() const
{
    return(const_cast<TargetPanelModel &>(mObjTargetPanelModel));
}

void SetupModel::setResumeFromLastPosition(const bool bResumeFromLastPosition)
{
    mbResumeFromLastPosition = bResumeFromLastPosition;

    setChanged();
    notifyObservers("ResumeFromLastPosition");
}
