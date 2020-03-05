#include "ProcessCurrentFileObserver.h"
#include "ProcessModel.h"

using net::draconia::FileCopier::model::ProcessModel;
using namespace net::draconia::FileCopier::observers;

QLabel *ProcessCurrentFileObserver::getCurrentFileLabel()
{
    return(mLblCurrentFile);
}

ProcessCurrentFileObserver::ProcessCurrentFileObserver(QLabel *lblCurrentFile)
    :   Observer()
    ,   mLblCurrentFile(lblCurrentFile)
{ }

void ProcessCurrentFileObserver::update(const Observable &refObservable, const QString &sProperty)
{
    if(sProperty == "CurrentFile")
        {
        ProcessModel &refModel = static_cast<ProcessModel &>(const_cast<Observable &>(refObservable));

        if(refModel.getCurrentFile() != getCurrentFileLabel()->text())
            getCurrentFileLabel()->setText(refModel.getCurrentFile());
        }
}
