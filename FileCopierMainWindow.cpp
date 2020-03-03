#include "FileCopierMainWindow.h"
#include <QCloseEvent>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSplitter>

using net::draconia::FileCopier::FileCopierController;
using namespace net::draconia::FileCopier::ui;

void FileCopierMainWindow::closeEvent(QCloseEvent *event)
{
    if(!getController().isNormalExit())
        if(QMessageBox::question(this, "Exit File Copier...", "Are you sure you want to exit?") == QMessageBox::Yes)
            event->accept();
        else
            event->ignore();
    else
        event->accept();
}

void FileCopierMainWindow::initControls()
{
    setCentralWidget(getMainPanel());
}

void FileCopierMainWindow::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    setWindowTitle("File Copier");

    initControls();

    setStyleSheet("background-color: black;color: white;");
}

FileCopierMainWindow::FileCopierMainWindow(QWidget *parent, FileCopierController &refController)
    :   QMainWindow(parent)
    ,   mRefController(refController)
    ,   mPnlMain(nullptr)
{
    initPanel();
}

FileCopierController &FileCopierMainWindow::getController()
{
    return(mRefController);
}

FileCopierMainPanel *FileCopierMainWindow::getMainPanel()
{
    if(mPnlMain == nullptr)
        mPnlMain = new FileCopierMainPanel(this, getController());

    return(mPnlMain);
}
