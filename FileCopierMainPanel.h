#pragma once

#include "FileCopierButtonPanel.h"
#include "FileCopierController.h"
#include "ProcessPanel.h"
#include <QSplitter>
#include <QWidget>
#include "SetupPanel.h"

using net::draconia::FileCopier::FileCopierController;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace ui
            {
                class FileCopierMainPanel : public QWidget
                {
                    Q_OBJECT

                    FileCopierButtonPanel *mPnlButtons;
                    FileCopierController &mRefController;
                    QSplitter *mPnlSplitter;
                    ProcessPanel *mPnlProcess;
                    SetupPanel *mPnlSetup;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    FileCopierMainPanel(QWidget *parent, FileCopierController &refController);

                    FileCopierButtonPanel *getButtonPanel();
                    FileCopierController &getController();
                    ProcessPanel *getProcessPanel();
                    SetupPanel *getSetupPanel();
                    QSplitter *getSplitterPanel();
                signals:
                };
            }
        }
    }
}
