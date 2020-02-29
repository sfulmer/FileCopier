#include "FileCopierMainPanel.h"
#include <QVBoxLayout>

using namespace net::draconia::FileCopier::ui;

void FileCopierMainPanel::initControls()
{
    QLayout *layout = new QVBoxLayout(this);

    layout->addWidget(getSplitterPanel());
    layout->addWidget(getButtonPanel());
}

void FileCopierMainPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

FileCopierMainPanel::FileCopierMainPanel(QWidget *parent, FileCopierController &refController)
    :   QWidget(parent)
    ,   mPnlButtons(nullptr)
    ,   mRefController(refController)
    ,   mPnlSplitter(nullptr)
    ,   mPnlProcess(nullptr)
    ,   mPnlSetup(nullptr)
{
    initPanel();
}

FileCopierButtonPanel *FileCopierMainPanel::getButtonPanel()
{
    if(mPnlButtons == nullptr)
        mPnlButtons = new FileCopierButtonPanel(this, getController());

    return(mPnlButtons);
}

FileCopierController &FileCopierMainPanel::getController()
{
    return(mRefController);
}

ProcessPanel *FileCopierMainPanel::getProcessPanel()
{
    if(mPnlProcess == nullptr)
        {
        mPnlProcess = new ProcessPanel(this, getController().getSetupModel());

        mPnlProcess->sizePolicy().setHorizontalStretch(2);
        }

    return(mPnlProcess);
}

SetupPanel *FileCopierMainPanel::getSetupPanel()
{
    if(mPnlSetup == nullptr)
        {
        mPnlSetup = new SetupPanel(this, getController().getSetupModel());

        mPnlSetup->sizePolicy().setHorizontalStretch(1);
        }

    return(mPnlSetup);
}

QSplitter *FileCopierMainPanel::getSplitterPanel()
{
    if(mPnlSplitter == nullptr)
        {
        mPnlSplitter = new QSplitter(Qt::Orientation::Horizontal, this);

        mPnlSplitter->addWidget(getSetupPanel());
        mPnlSplitter->addWidget(getProcessPanel());
        }

    return(mPnlSplitter);
}
