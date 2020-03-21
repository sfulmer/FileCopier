#include "FileCopierApp.h"
#include "PropertyFileIO.h"

using namespace net::draconia;
using net::draconia::io::PropertyFileIO;

void FileCopierApp::propogatePropertiesToSettings()
{
    getController().setUp(getProperties());
}

void FileCopierApp::setArguments(int argc, char *argv[])
{
    for(int iLength = argc, iLoop = 0; iLoop < iLength; iLoop++)
        mLstArgs.append(argv[iLoop]);
}

void FileCopierApp::showMainWindow()
{
    getMainWindow().show();
}

FileCopierApp::FileCopierApp(int argc, char *argv[])
    :   QApplication(argc, argv)
    ,   mObjController(*this)
    ,   mWndMain(nullptr, getController())
{
    setArguments(argc, argv);
}

int FileCopierApp::exec()
{
    propogatePropertiesToSettings();

    showMainWindow();

    return(QApplication::exec());
}

void FileCopierApp::exit()
{
    getMainWindow().close();
}

FileCopierController &FileCopierApp::getController()
{
    return(mObjController);
}

FileCopierMainWindow &FileCopierApp::getMainWindow()
{
    return(mWndMain);
}

Properties &FileCopierApp::getProperties()
{
    if(mObjProperties.isEmpty())
        return(mObjProperties = PropertyFileIO().load("Config.properties"));
    else
        return(mObjProperties);
}
