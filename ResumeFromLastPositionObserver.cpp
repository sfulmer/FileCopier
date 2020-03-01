#include "ResumeFromLastPositionObserver.h"
#include "SetupModel.h"

using net::draconia::FileCopier::model::SetupModel;
using namespace net::draconia::FileCopier::observers;

QCheckBox *ResumeFromLastPositionObserver::getResumeFromLastPositionCheckbox()
{
    return(mChkResumeFromLastPosition);
}

ResumeFromLastPositionObserver::ResumeFromLastPositionObserver(QCheckBox *chkResumeFromLastPosition)
    :   Observer()
    ,   mChkResumeFromLastPosition(chkResumeFromLastPosition)
{ }

void ResumeFromLastPositionObserver::update(const Observable &objObservable, const QString &sProperty)
{
    if(sProperty == "ResumeFromLastPosition")
        {
        bool bChecked = (getResumeFromLastPositionCheckbox()->checkState() == Qt::CheckState::Checked);
        SetupModel &refModel = static_cast<SetupModel &>(const_cast<Observable &>(objObservable));

        if(refModel.getResumeFromLastPosition() != bChecked)
            getResumeFromLastPositionCheckbox()->setCheckState(bChecked ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
        }
}
