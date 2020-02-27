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

                    QSharedPointer<ProcessModel> mPtrModel;
                    QPushButton *mBtnCancel, *mBtnPauseResume;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    explicit ProcessButtonPanel(QWidget *parent = nullptr);
                    ProcessButtonPanel(QWidget *parent, const ProcessModel &refModel);
                    ~ProcessButtonPanel();

                    QPushButton *getCancelButton();
                    ProcessModel &getModel();
                    QPushButton *getPauseResumeButton();
                    void setModel(const ProcessModel &refModel);
                signals:

                };
            }
        }
    }
}
