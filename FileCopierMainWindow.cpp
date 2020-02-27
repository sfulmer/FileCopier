#include "FileCopierMainWindow.h"
#include <QHBoxLayout>
#include <QSplitter>

using namespace net::draconia::FileCopier::ui;

void FileCopierMainWindow::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    setLayout(layout);

    layout->addWidget(getSplitterPanel());
}

void FileCopierMainWindow::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

FileCopierMainWindow::FileCopierMainWindow(QWidget *parent)
    :   QMainWindow(parent)
    ,   mPnlSplitter(nullptr)
    ,   mPnlSetup(nullptr)
{
    initPanel();
}

FileCopierMainWindow::~FileCopierMainWindow()
{ }

void FileCopierMainWindow::getProcessPanel()
{
    // TODO
}

SetupPanel *FileCopierMainWindow::FileCopierMainWindow::getSetupPanel()
{
    if(mPnlSetup == nullptr)
        mPnlSetup = new SetupPanel(this);

    return(mPnlSetup);
}

QSplitter *FileCopierMainWindow::getSplitterPanel()
{
    if(mPnlSplitter == nullptr)
        {
        mPnlSplitter = new QSplitter(Qt::Orientation::Horizontal, this);

        mPnlSplitter->addWidget(getSetupPanel());
        //mPnlSplitter->addWidget(getProcessPanel());
        }

    return(mPnlSplitter);
}
