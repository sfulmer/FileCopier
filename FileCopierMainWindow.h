#pragma once

#include "FileCopierController.h"
#include "FileCopierMainPanel.h"
#include <QMainWindow>

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
                    FileCopierMainPanel *mPnlMain;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    FileCopierMainWindow(QWidget *parent, FileCopierController &refController);

                    FileCopierController &getController();
                    FileCopierMainPanel *getMainPanel();
                };
            }
        }
    }
}
