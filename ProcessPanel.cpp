#include "FileCopierController.h"
#include "ProcessPanel.h"
#include "ProgressObserver.h"
#include <QVBoxLayout>

using net::draconia::FileCopier::FileCopierController;
using net::draconia::FileCopier::observers::ProgressObserver;
using namespace net::draconia::FileCopier::ui;

void ProcessPanel::initControls()
{
    QLayout *layout = new QVBoxLayout(this);

    setLayout(layout);

    layout->addWidget(getFilenamePanel());
    layout->addWidget(getProgressBar());
    layout->addWidget(getStatusPanel());
    layout->addWidget(getButtonPanel());
}

void ProcessPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

ProcessPanel::ProcessPanel(QWidget *parent, SetupModel &refSetupModel)
    :   QWidget(parent)
    ,   mPnlButtons(nullptr)
    ,   mPnlFilename(nullptr)
    ,   mObjProcessModel(refSetupModel.getController().getProcessModel())
    ,   mPnlStatus(nullptr)
    ,   mBarProgress(nullptr)
    ,   mRefSetupModel(refSetupModel)
{
    getProcessModel().addObserver(new ProgressObserver(getProgressBar()));

    initPanel();
}

ProcessButtonPanel *ProcessPanel::getButtonPanel()
{
    if(mPnlButtons == nullptr)
        mPnlButtons = new ProcessButtonPanel(this, getProcessModel());

    return(mPnlButtons);
}

ProcessFilenamePanel *ProcessPanel::getFilenamePanel()
{
    if(mPnlFilename == nullptr)
        mPnlFilename = new ProcessFilenamePanel(this, getProcessModel());

    return(mPnlFilename);
}

ProcessModel &ProcessPanel::getProcessModel()
{
    return(mObjProcessModel);
}

QProgressBar *ProcessPanel::getProgressBar()
{
    if(mBarProgress == nullptr)
        {
        mBarProgress = new QProgressBar(this);

        mBarProgress->setMaximum(100);
        mBarProgress->setMinimum(0);
        mBarProgress->setTextVisible(true);
        mBarProgress->setAlignment(Qt::AlignCenter);
        }

    return(mBarProgress);
}

const SetupModel &ProcessPanel::getSetupModel() const
{
    return(mRefSetupModel);
}

ProcessStatusPanel *ProcessPanel::getStatusPanel()
{
    if(mPnlStatus == nullptr)
        mPnlStatus = new ProcessStatusPanel(this, getProcessModel());

    return(mPnlStatus);
}
