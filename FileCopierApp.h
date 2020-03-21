#pragma once

#include "FileCopierController.h"
#include "FileCopierMainWindow.h"
#include "Properties.h"
#include <QApplication>
#include <QList>

using net::draconia::FileCopier::FileCopierController;
using net::draconia::FileCopier::ui::FileCopierMainWindow;
using net::draconia::util::Properties;

namespace net
{
    namespace draconia
    {
        class FileCopierApp : public QApplication
        {
            FileCopierController mObjController;
            FileCopierMainWindow mWndMain;
            Properties mObjProperties;
            QList<QString> mLstArgs;
        protected:
            void propogatePropertiesToSettings();
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
            Properties &getProperties();
            void start();
        };
    }
}
