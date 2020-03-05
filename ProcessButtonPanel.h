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
                    QPushButton *mBtnPauseResume;
                protected:
                    void initControls();
                    void initPanel();

                    void pauseResumeProcess();
                public:
                    ProcessButtonPanel(QWidget *parent, const ProcessModel &refModel);

                    ProcessModel &getModel();
                    QPushButton *getPauseResumeButton();
                signals:

                };
            }
        }
    }
}
