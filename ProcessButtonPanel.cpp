#include "ProcessButtonPanel.h"
#include <QHBoxLayout>

using namespace net::draconia::FileCopier::ui;

void ProcessButtonPanel::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    setLayout(layout);

    layout->addWidget(getPauseResumeButton());
    layout->addWidget(getCancelButton());
}

void ProcessButtonPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));

    initControls();
}

ProcessButtonPanel::ProcessButtonPanel(QWidget *parent)
    :   QWidget(parent)
    ,   mPtrModel(nullptr)
{ }

ProcessButtonPanel::ProcessButtonPanel(QWidget *parent, const ProcessModel &refModel)
    :   QWidget(parent)
    ,   mPtrModel(&const_cast<ProcessModel &>(refModel))
{ }

ProcessButtonPanel::~ProcessButtonPanel()
{
    mPtrModel.reset();
}

QPushButton *ProcessButtonPanel::getCancelButton()
{
    if(mBtnCancel == nullptr)
        mBtnCancel = new QPushButton("Cancel", this);

    return(mBtnCancel);
}

ProcessModel &ProcessButtonPanel::getModel()
{
    if(!mPtrModel.isNull())
        return(*mPtrModel);
}

QPushButton *ProcessButtonPanel::getPauseResumeButton()
{
    if(mBtnPauseResume == nullptr)
        mBtnPauseResume = new QPushButton("Start", this);

    return(mBtnPauseResume);
}

void ProcessButtonPanel::setModel(const ProcessModel &refModel)
{
    mPtrModel.reset(&const_cast<ProcessModel &>(refModel));
}
