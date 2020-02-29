#include "ProcessButtonPanel.h"
#include <QHBoxLayout>

using namespace net::draconia::FileCopier::ui;

void ProcessButtonPanel::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    setLayout(layout);

    layout->addWidget(getPauseResumeButton());
}

void ProcessButtonPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));

    initControls();
}

ProcessButtonPanel::ProcessButtonPanel(QWidget *parent, const ProcessModel &refModel)
    :   QWidget(parent)
    ,   mRefModel(const_cast<ProcessModel &>(refModel))
    ,   mBtnPauseResume(nullptr)
{
    initPanel();
}

ProcessModel &ProcessButtonPanel::getModel()
{
    return(mRefModel);
}

QPushButton *ProcessButtonPanel::getPauseResumeButton()
{
    if(mBtnPauseResume == nullptr)
        {
        mBtnPauseResume = new QPushButton("Resume", this);

        mBtnPauseResume->setDisabled(true);
        }

    return(mBtnPauseResume);
}
