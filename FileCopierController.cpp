#include "FileCopierController.h"

using namespace net::draconia::FileCopier;
using net::draconia::FileCopier::model::ProcessModel;
using net::draconia::FileCopier::model::SetupModel;

FileCopierController::FileCopierController()
    :   mObjProcessModel(*this)
    ,   mObjSetupModel(*this)
{ }

SetupModel &FileCopierController::getSetupModel() const
{
    return(const_cast<SetupModel &>(mObjSetupModel));
}

void FileCopierController::cancelProcess()
{
    // TODO Put code in here
}

void FileCopierController::exit()
{
    //TODO Put code here
}

void FileCopierController::pauseProcess()
{
    // TODO Put code in here
}

ProcessModel &FileCopierController::getProcessModel() const
{
    return(const_cast<ProcessModel &>(mObjProcessModel));
}

void FileCopierController::resumeProcess()
{
    //TODO Put code in here
}

void FileCopierController::startProcess()
{
    //TODO Put code in here
}
