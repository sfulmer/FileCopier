#pragma once

#include "Observer.h"
#include <QCheckBox>

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace observers
            {
                class ResumeFromLastPositionObserver : public Observer
                {
                    QCheckBox *mChkResumeFromLastPosition;
                protected:
                    QCheckBox *getResumeFromLastPositionCheckbox();
                public:
                    ResumeFromLastPositionObserver(QCheckBox *chkResumeFromLastPosition);

                    virtual void update(const Observable &objObservable, const QString &sProperty);
                };
            }
        }
    }
}
