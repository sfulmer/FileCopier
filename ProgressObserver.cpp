#include "ProcessModel.h"
#include "ProgressObserver.h"

using net::draconia::FileCopier::model::ProcessModel;
using namespace net::draconia::FileCopier::observers;

QProgressBar *ProgressObserver::getProgressBar()
{
    return(mBarProgress);
}

ProgressObserver::ProgressObserver(QProgressBar *barProgress)
    :   Observer()
    ,   mBarProgress(barProgress)
{ }

void ProgressObserver::update(const Observable &refObservable, const QString &sProperty)
{
    if((sProperty == "CurrentBytesMoved") || (sProperty == "TotalBytesToMove"))
        {
        float fPercent = 0.0f;
        ProcessModel &refModel = static_cast<ProcessModel &>(const_cast<Observable &>(refObservable));

        fPercent = ((float)refModel.getCurrentBytesMoved()) / ((float)refModel.getTotalBytesToMove()) * 100;

        getProgressBar()->setValue(fPercent);
        }
}
