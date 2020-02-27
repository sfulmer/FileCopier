#include "FileCopierModel.h"

using net::draconia::FileCopier::FileCopierController;
using namespace net::draconia::FileCopier::model;

FileCopierModel::FileCopierModel(FileCopierController &refController)
    :   Observable()
    ,   mbRestartFromLastPosition(true)
    ,   mRefController(refController)
{ }

FileCopierModel::FileCopierModel(FileCopierController &refController, const SourcePanelModel &refSourceModel, const TargetPanelModel &refTargetModel)
    :   Observable()
    ,   mbRestartFromLastPosition(true)
    ,   mRefController(refController)
    ,   mObjSourcePanelModel(refSourceModel)
    ,   mObjTargetPanelModel(refTargetModel)
{ }

FileCopierModel::FileCopierModel(const FileCopierModel &refCopy)
    :   Observable(refCopy)
    ,   mbRestartFromLastPosition(refCopy.getRestartFromLastPosition())
    ,   mRefController(refCopy.getController())
    ,   mObjSourcePanelModel(refCopy.getSourcePanelModel())
    ,   mObjTargetPanelModel(refCopy.getTargetPanelModel())
{ }

FileCopierController &FileCopierModel::getController() const
{
    return(const_cast<FileCopierController &>(mRefController));
}

bool FileCopierModel::getRestartFromLastPosition() const
{
    return(mbRestartFromLastPosition);
}

SourcePanelModel &FileCopierModel::getSourcePanelModel() const
{
    return(const_cast<SourcePanelModel &>(mObjSourcePanelModel));
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
