#pragma once

#include "ProcessModel.h"
#include <QPushButton>
#include <QSharedPointer>
#include <QWidget>

using namespace net::draconia::FileCopier::model;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace ui
            {
                class ProcessButtonPanel : public QWidget
                {
                    Q_OBJECT

                    ProcessModel &mRefModel;
                    QPushButton *mBtnCancel, *mBtnPauseResume;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    ProcessButtonPanel(QWidget *parent, const ProcessModel &refModel);

                    QPushButton *getCancelButton();
                    ProcessModel &getModel();
                    QPushButton *getPauseResumeButton();
                signals:

                };
            }
        }
    }
}
