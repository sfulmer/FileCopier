#include "ExitWhenDoneObserver.h"
#include "SetupModel.h"

using net::draconia::FileCopier::model::SetupModel;
using namespace net::draconia::FileCopier::observers;

QCheckBox *ExitWhenDoneObserver::getExitWhenDoneCheckBox()
{
    return(mChkExitWhenDone);
}

ExitWhenDoneObserver::ExitWhenDoneObserver(QCheckBox *chkExitWhenDone)
    :   Observer()
    ,   mChkExitWhenDone(chkExitWhenDone)
{ }

void ExitWhenDoneObserver::update(const Observable &objObservable, const QString &sProperty)
{
    if(sProperty.contains("Exit"))
        {
        bool bChecked = (getExitWhenDoneCheckBox()->checkState() == Qt::CheckState::Checked);
        SetupModel &refModel = static_cast<SetupModel &>(const_cast<Observable &>(objObservable));

        if(refModel.getExitWhenDone() != bChecked)
            getExitWhenDoneCheckBox()->setCheckState(bChecked ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
        }
}
