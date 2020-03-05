#pragma once

#include "Observer.h"
#include <QProgressBar>

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace observers
            {
                class ProgressObserver : public Observer
                {
                    QProgressBar *mBarProgress;
                protected:
                    QProgressBar *getProgressBar();
                public:
                    ProgressObserver(QProgressBar *barProgress);

                    virtual void update(const Observable &refObservable, const QString &sProperty);
                };
            }
        }
    }
}
