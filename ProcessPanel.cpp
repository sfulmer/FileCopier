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
}

ProcessPanel::ProcessPanel(QWidget *parent)
    :   QWidget(parent)
    ,   mPtrFileCopierModel(nullptr)
    ,   mPnlButtons(nullptr)
    ,   mPnlFilename(nullptr)
    ,   mBarProgress(nullptr)
{ }

ProcessPanel::ProcessPanel(QWidget *parent, FileCopierModel &refModel)
    :   QWidget(parent)
    ,   mPtrFileCopierModel(&refModel)
    ,   mPnlButtons(nullptr)
    ,   mPnlFilename(nullptr)
    ,   mBarProgress(nullptr)
{ }

ProcessButtonPanel *ProcessPanel::getButtonPanel()
{
    if(mPnlButtons == nullptr)
        mPnlButtons = new ProcessButtonPanel(this, getProcessModel());

    return(mPnlButtons);
}

const FileCopierModel &ProcessPanel::getFileCopierModel() const
{
    return(*mPtrFileCopierModel);
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
