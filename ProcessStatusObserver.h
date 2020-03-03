#pragma once

#include "Observer.h"
#include <QLabel>

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace observers
            {
                class ProcessStatusObserver : public Observer
                {
                    QLabel *mLblStatus;
                protected:
                    QLabel *getStatusLabel();
                public:
                    ProcessStatusObserver(QLabel *lblStatus);

                    virtual void update(const Observable &refObservable, const QString &sProperty);
                };
            }
        }
    }
}
