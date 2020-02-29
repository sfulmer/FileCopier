#pragma once

#include "ProcessModel.h"
#include <QLabel>
#include <QWidget>

using net::draconia::FileCopier::model::ProcessModel;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace ui
            {
                class ProcessStatusPanel : public QWidget
                {
                    Q_OBJECT

                    ProcessModel &mRefModel;
                    QLabel *mLblStatus, *mLblStatusText;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    ProcessStatusPanel(QWidget *parent, ProcessModel &refModel);

                    ProcessModel &getModel();
                    QLabel *getStatusLabel();
                    QLabel *getStatusText();
                signals:

                };
            }
        }
    }
}
