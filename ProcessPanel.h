#pragma once

#include "ProcessButtonPanel.h"
#include "ProcessFilenamePanel.h"
#include "ProcessModel.h"
#include "ProcessStatusPanel.h"
#include <QProgressBar>
#include <QPushButton>
#include <QWidget>
#include "SetupModel.h"

using namespace net::draconia::FileCopier::model;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace ui
            {
                class ProcessPanel : public QWidget
                {
                    Q_OBJECT

                    ProcessButtonPanel *mPnlButtons;
                    ProcessFilenamePanel *mPnlFilename;
                    ProcessModel mObjProcessModel;
                    ProcessStatusPanel *mPnlStatus;
                    QProgressBar *mBarProgress;
                    SetupModel &mRefSetupModel;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    ProcessPanel(QWidget *parent, SetupModel &refSetupModel);

                    ProcessButtonPanel *getButtonPanel();
                    ProcessFilenamePanel *getFilenamePanel();
                    ProcessModel &getProcessModel();
                    QProgressBar *getProgressBar();
                    const SetupModel &getSetupModel() const;
                    ProcessStatusPanel *getStatusPanel();
                signals:

                };
            }
        }
    }
}
