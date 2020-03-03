#include "ProcessModel.h"
#include "ProcessStatusObserver.h"

using net::draconia::FileCopier::model::ProcessModel;
using namespace net::draconia::FileCopier::observers;

QLabel *ProcessStatusObserver::getStatusLabel()
{
    return(mLblStatus);
}

ProcessStatusObserver::ProcessStatusObserver(QLabel *lblStatus)
    :   Observer()
    ,   mLblStatus(lblStatus)
{ }

void ProcessStatusObserver::update(const Observable &refObservable, const QString &sProperty)
{
    if(sProperty == "Status")
        {
        ProcessModel &refModel = static_cast<ProcessModel &>(const_cast<Observable &>(refObservable));

        if(refModel.getStatus().getText() != getStatusLabel()->text())
            getStatusLabel()->setText(refModel.getStatus().getText());
        }
}
