#include "FileCopierApp.h"

using namespace net::draconia;

FileCopierApp::RunningState FileCopierApp::getRunningState() const
{
    return(meRunningState);
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
    ,   mWndMain(nullptr, getController())
{
    setArguments(argc, argv);
}

int FileCopierApp::exec()
{
    showMainWindow();

    return(QApplication::exec());
}

FileCopierController &FileCopierApp::getController()
{
    return(mObjController);
}

FileCopierMainWindow &FileCopierApp::getMainWindow()
{
    return(mWndMain);
}
