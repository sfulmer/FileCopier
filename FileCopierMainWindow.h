#pragma once

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

                    QSplitter *mPnlSplitter;
                    SetupPanel *mPnlSetup;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    FileCopierMainWindow(QWidget *parent = nullptr);
                    ~FileCopierMainWindow();

                    void getProcessPanel();
                    SetupPanel *getSetupPanel();
                    QSplitter *getSplitterPanel();
                };
            }
        }
    }
}
