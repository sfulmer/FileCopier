#include "FileCopierController.h"
#include "ProcessModel.h"
#include "SetupModel.h"
#include "StatusDoneObserver.h"

using net::draconia::FileCopier::FileCopierController;
using net::draconia::FileCopier::model::ProcessModel;
using net::draconia::FileCopier::model::SetupModel;
using namespace net::draconia::FileCopier::observers;

void StatusDoneObserver::update(const Observable &refObservable, const QString &sProperty)
{
    if(sProperty == "Status")
        {
        ProcessModel &refModel = static_cast<ProcessModel &>(const_cast<Observable &>(refObservable));

        if(refModel.isDone() && refModel.getController().getSetupModel().getExitWhenDone())
            refModel.getController().exit(true);
        }
}
