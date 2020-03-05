#include "ProcessModel.h"
#include "StatusMovingPausedStalledObserver.h"

using net::draconia::FileCopier::model::ProcessModel;
using namespace net::draconia::FileCopier::observers;

QPushButton *StatusMovingPausedStalledObserver::getPauseResumeButton()
{
    return(mBtnPauseResume);
}

StatusMovingPausedStalledObserver::StatusMovingPausedStalledObserver(QPushButton *btnPauseResume)
    :   Observer()
    ,   mBtnPauseResume(btnPauseResume)
{ }

void StatusMovingPausedStalledObserver::update(const Observable &refObservable, const QString &sProperty)
{
    if(sProperty == "Status")
        {
        ProcessModel &refModel = static_cast<ProcessModel &>(const_cast<Observable &>(refObservable));

        if(refModel.isPaused() || refModel.isStalled())
            getPauseResumeButton()->setText("Resume");
        else if(refModel.isMoving())
            getPauseResumeButton()->setText("Pause");
        }
}
