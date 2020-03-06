#pragma once

#include "FileCopierController.h"
#include "FileCopierMainWindow.h"
#include "PropertyFileIO.h"
#include <QApplication>
#include <QList>

using net::draconia::FileCopier::FileCopierController;
using net::draconia::FileCopier::ui::FileCopierMainWindow;
using net::draconia::io::Property;
using net::draconia::io::PropertyFileIO;

namespace net
{
    namespace draconia
    {
        class FileCopierApp : public QApplication
        {
            FileCopierController mObjController;
            FileCopierMainWindow mWndMain;
            PropertyFileIO mFileProperties;
            QList<QString> mLstArgs;
        protected:
            PropertyFileIO &getPropertyFile() const;
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
            QList<Property> &getProperties();
            void start();
        };
    }
}
