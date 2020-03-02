#pragma once

#include <QCheckBox>
#include "Observer.h"

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace observers
            {
                class ExitWhenDoneObserver : public Observer
                {
                    QCheckBox *mChkExitWhenDone;
                protected:
                    QCheckBox *getExitWhenDoneCheckBox();
                public:
                    ExitWhenDoneObserver(QCheckBox *chkExitWhenDone);

                    virtual void update(const Observable &objObservable, const QString &sProperty);
                };
            }
        }
    }
}
