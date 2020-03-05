#include "ProcessButtonPanel.h"
#include <QHBoxLayout>
#include "StatusMovingPausedStalledObserver.h"

using net::draconia::FileCopier::observers::StatusMovingPausedStalledObserver;
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

void ProcessButtonPanel::pauseResumeProcess()
{
    if(getModel().isMoving())
        getModel().pause();
    else if(getModel().isStalled() || getModel().isPaused())
        getModel().resume();
}

ProcessButtonPanel::ProcessButtonPanel(QWidget *parent, const ProcessModel &refModel)
    :   QWidget(parent)
    ,   mRefModel(const_cast<ProcessModel &>(refModel))
    ,   mBtnPauseResume(nullptr)
{
    getModel().addObserver(new StatusMovingPausedStalledObserver(getPauseResumeButton()));

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

        connect(mBtnPauseResume, &QPushButton::clicked, this, &ProcessButtonPanel::pauseResumeProcess);

        mBtnPauseResume->setDisabled(true);
        }

    return(mBtnPauseResume);
}
