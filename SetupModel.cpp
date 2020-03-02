#include "FileCopierController.h"
#include "SetupModel.h"

using net::draconia::FileCopier::FileCopierController;
using namespace net::draconia::FileCopier::model;
using namespace net::draconia::util;

SetupModel::SetupModel(FileCopierController &refController)
    :   Observable()
    ,   mbExitWhenDone(true)
    ,   mbResumeFromLastPosition(true)
    ,   mRefController(refController)
{
    getSourcePanelModel().addObserver(this);
    getTargetPanelModel().addObserver(this);
}

SetupModel::SetupModel(FileCopierController &refController, const SourcePanelModel &refSourceModel, const TargetPanelModel &refTargetModel)
    :   Observable()
    ,   mbExitWhenDone(true)
    ,   mbResumeFromLastPosition(true)
    ,   mRefController(refController)
    ,   mObjSourcePanelModel(refSourceModel)
    ,   mObjTargetPanelModel(refTargetModel)
{
    getSourcePanelModel().addObserver(this);
    getTargetPanelModel().addObserver(this);
}

SetupModel::SetupModel(const SetupModel &refCopy)
    :   Observable(refCopy)
    ,   mbExitWhenDone(refCopy.getExitWhenDone())
    ,   mbResumeFromLastPosition(refCopy.getResumeFromLastPosition())
    ,   mRefController(refCopy.getController())
    ,   mObjSourcePanelModel(refCopy.getSourcePanelModel())
    ,   mObjTargetPanelModel(refCopy.getTargetPanelModel())
{
    getSourcePanelModel().addObserver(this);
    getTargetPanelModel().addObserver(this);
}

FileCopierController &SetupModel::getController() const
{
    return(const_cast<FileCopierController &>(mRefController));
}

bool SetupModel::getExitWhenDone() const
{
    return(mbExitWhenDone);
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

void SetupModel::setExitWhenDone(const bool bExitWhenDone)
{
    mbExitWhenDone = bExitWhenDone;

    setChanged();
    notifyObservers("ExitWhenDone");
}

void SetupModel::setResumeFromLastPosition(const bool bResumeFromLastPosition)
{
    mbResumeFromLastPosition = bResumeFromLastPosition;

    setChanged();
    notifyObservers("ResumeFromLastPosition");
}

void SetupModel::update(const Observable &objObservable, const QString &sProperty)
{
    Q_UNUSED(objObservable);

    setChanged();

    if(sProperty.contains("Source"))
        notifyObservers("Source");
    else
        notifyObservers("Target");
}
