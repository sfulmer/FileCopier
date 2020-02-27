#pragma once

#include "FileCopierController.h"
#include <QPushButton>
#include <QWidget>


namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace ui
            {
                class SetupButtonPanel : public QWidget
                {
                    Q_OBJECT

                    FileCopierController &mRefController;
                    QPushButton *mBtnExit, *mBtnStart;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    SetupButtonPanel(QWidget *parent, FileCopierController &refController);

                    FileCopierController &getController() const;
                    QPushButton *getExitButton();
                    QPushButton *getStartButton();
                signals:

                };
            }
        }
    }
}
