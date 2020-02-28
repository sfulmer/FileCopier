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

ProcessButtonPanel::ProcessButtonPanel(QWidget *parent, const ProcessModel &refModel)
    :   QWidget(parent)
    ,   mRefModel(const_cast<ProcessModel &>(refModel))
{ }

QPushButton *ProcessButtonPanel::getCancelButton()
{
    if(mBtnCancel == nullptr)
        mBtnCancel = new QPushButton("Cancel", this);

    return(mBtnCancel);
}

ProcessModel &ProcessButtonPanel::getModel()
{
    return(mRefModel);
}

QPushButton *ProcessButtonPanel::getPauseResumeButton()
{
    if(mBtnPauseResume == nullptr)
        mBtnPauseResume = new QPushButton("Start", this);

    return(mBtnPauseResume);
}
