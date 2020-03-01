#pragma once

#include "FileCopierController.h"
#include "FileCopierMainWindow.h"
#include <QApplication>
#include <QList>

using net::draconia::FileCopier::FileCopierController;
using net::draconia::FileCopier::ui::FileCopierMainWindow;

namespace net
{
    namespace draconia
    {
        class FileCopierApp : public QApplication
        {
            enum RunningState
            {   Started
            ,   Stopped
            ,   Error
            } meRunningState;

            FileCopierController mObjController;
            FileCopierMainWindow mWndMain;
            QList<QString> mLstArgs;
        protected:
            RunningState getRunningState() const;
            void setArguments(int argc, char *argv[]);
            void showMainWindow();
        public:
            FileCopierApp(int argc, char *argv[]);
            void error();
            int exec();
            void exit();
            QList<QString> &getArguments() const;
            FileCopierController &getController();
            FileCopierMainWindow &getMainWindow();
            void start();
        };
    }
}
