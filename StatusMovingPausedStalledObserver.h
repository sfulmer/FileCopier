#pragma once

#include "Observer.h"
#include <QPushButton>

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace observers
            {
                class StatusMovingPausedStalledObserver : public Observer
                {
                    QPushButton *mBtnPauseResume;
                protected:
                    QPushButton *getPauseResumeButton();
                public:
                    StatusMovingPausedStalledObserver(QPushButton *btnPauseResume);

                    virtual void update(const Observable &refObservable, const QString &sProperty);
                };
            }
        }
    }
}
