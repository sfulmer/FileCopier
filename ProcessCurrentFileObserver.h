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
                class ProcessCurrentFileObserver : public Observer
                {
                    QLabel *mLblCurrentFile;
                protected:
                    QLabel *getCurrentFileLabel();
                public:
                    ProcessCurrentFileObserver(QLabel *lblCurrentFile);

                    virtual void update(const Observable &refObservable, const QString &sProperty);
                };
            }
        }
    }
}
