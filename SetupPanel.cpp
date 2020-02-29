#include <QVBoxLayout>
#include "SetupPanel.h"

using namespace net::draconia::FileCopier::ui;

void SetupPanel::initControls()
{
    QLayout *layout = new QVBoxLayout(this);

    setLayout(layout);

    layout->addWidget(getSourcePanel());
    layout->addWidget(getTargetPanel());
    layout->addWidget(getResumeFromLastPositionCheckBox());
    layout->addWidget(getButtonPanel());
}

void SetupPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));

    initControls();
}

SetupPanel::SetupPanel(QWidget *parent, SetupModel &refModel)
    :   QWidget(parent)
    ,   mChkResumeFromLastPosition(nullptr)
    ,   mPnlButtons(nullptr)
    ,   mRefSetupModel(refModel)
    ,   mPnlSource(nullptr)
    ,   mPnlTarget(nullptr)
{
    initPanel();
}

SetupButtonPanel *SetupPanel::getButtonPanel()
{
    if(mPnlButtons == nullptr)
        mPnlButtons = new SetupButtonPanel(this, getModel().getController());

    return(mPnlButtons);
}

SetupModel &SetupPanel::getModel() const
{
    return(mRefSetupModel);
}

QCheckBox *SetupPanel::getResumeFromLastPositionCheckBox()
{
    if(mChkResumeFromLastPosition == nullptr)
        mChkResumeFromLastPosition = new QCheckBox("&Resume from Last Position?", this);

    return(mChkResumeFromLastPosition);
}

SourcePanel *SetupPanel::getSourcePanel()
{
    if(mPnlSource == nullptr)
        mPnlSource = new SourcePanel(this, getModel().getSourcePanelModel());

    return(mPnlSource);
}

TargetPanel *SetupPanel::getTargetPanel()
{
    if(mPnlTarget == nullptr)
        mPnlTarget = new TargetPanel(this, getModel().getTargetPanelModel());

    return(mPnlTarget);
}
