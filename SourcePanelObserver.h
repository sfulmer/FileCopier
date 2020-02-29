#pragma once

#include "Observer.h"
#include <QLineEdit>

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace observers
            {
                class SourceFileObserver : public Observer
                {
                    QLineEdit *mTxtFieldTOEdit;
                protected:
                    QLineEdit *getFieldToEdit();
                public:
                    SourceFileObserver(QLineEdit *txtFieldToEdit);

                    virtual void update(const Observable &refObservable, const QString &sProperty);
                };
            }
        }
    }
}
