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
                class StartButtonObserver : public Observer
                {
                    QPushButton *mBtnStart;
                protected:
                    QPushButton *getStartButton();
                public:
                    StartButtonObserver(QPushButton *btnStart);

                    virtual void update(const Observable &objObservable, const QString &sProperty);
                };
            }
        }
    }
}
