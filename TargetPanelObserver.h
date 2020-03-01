#pragma once

#include "Observer.h"
#include <QLineEdit>
#include "TargetPanelModel.h"

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace observers
            {
                class TargetPanelObserver : public Observer
                {
                    QLineEdit *mTxtDirectory, *mTxtFilename;
                protected:
                    QLineEdit *getDirectoryField();
                    QLineEdit *getFilenameField();
                public:
                    TargetPanelObserver(QLineEdit *txtDirectory, QLineEdit *txtFilename);

                    virtual void update(const Observable &refObservable, const QString &sProperty);
                };
            }
        }
    }
}
