#include "ProcessPanel.h"
#include <QVBoxLayout>

using namespace net::draconia::FileCopier::ui;

void ProcessPanel::initControls()
{
    QLayout *layout = new QVBoxLayout(this);

    setLayout(layout);

    layout->addWidget(getFilenamePanel());
    layout->addWidget(getProgressBar());
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
    ,   mObjProcessModel(refSetupModel.getController())
    ,   mBarProgress(nullptr)
    ,   mRefSetupModel(refSetupModel)
{
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
        mBarProgress = new QProgressBar(this);

    return(mBarProgress);
}

const SetupModel &ProcessPanel::getSetupModel() const
{
    return(mRefSetupModel);
}
