#pragma once

#include "SetupModel.h"
#include "ProcessButtonPanel.h"
#include "ProcessModel.h"
#include "ProcessFilenamePanel.h"
#include <QProgressBar>
#include <QPushButton>
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
                class ProcessPanel : public QWidget
                {
                    Q_OBJECT

                    ProcessButtonPanel *mPnlButtons;
                    ProcessFilenamePanel *mPnlFilename;
                    ProcessModel mObjProcessModel;
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
                signals:

                };
            }
        }
    }
}
