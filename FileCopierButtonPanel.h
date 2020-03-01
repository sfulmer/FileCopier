#pragma once

#include "FileCopierController.h"
#include <QPushButton>
#include <QWidget>

using net::draconia::FileCopier::FileCopierController;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace ui
            {
                class FileCopierButtonPanel : public QWidget
                {
                    Q_OBJECT

                    FileCopierController &mRefController;
                    QPushButton *mBtnExit;
                protected:
                    void exitApplication();
                    void initControls();
                    void initPanel();
                public:
                    FileCopierButtonPanel(QWidget *parent, FileCopierController &refController);

                    QPushButton *getExitButton();
                    FileCopierController &getController();
                signals:

                };
            }
        }
    }
}
