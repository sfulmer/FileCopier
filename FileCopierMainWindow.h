#pragma once

#include "FileCopierController.h"
#include <QMainWindow>
#include <QSplitter>
#include "SetupPanel.h"

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace ui
            {
                class FileCopierMainWindow : public QMainWindow
                {
                    Q_OBJECT

                    FileCopierController &mRefController;
                    QSplitter *mPnlSplitter;
                    SetupPanel *mPnlSetup;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    FileCopierMainWindow(QWidget *parent, FileCopierController &refController);
                    ~FileCopierMainWindow();

                    FileCopierController &getController() const;
                    void getProcessPanel();
                    SetupPanel *getSetupPanel();
                    QSplitter *getSplitterPanel();
                };
            }
        }
    }
}
