#include <QVBoxLayout>
#include "ResumeFromLastPositionObserver.h"
#include "SetupPanel.h"

using net::draconia::FileCopier::observers::ResumeFromLastPositionObserver;
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

void SetupPanel::resumeFromLastPositionClicked()
{
    bool bChecked = getResumeFromLastPositionCheckBox()->checkState() == Qt::CheckState::Checked;

    if(getModel().getResumeFromLastPosition() != bChecked)
        getModel().setResumeFromLastPosition(bChecked);
}

SetupPanel::SetupPanel(QWidget *parent, SetupModel &refModel)
    :   QWidget(parent)
    ,   mChkResumeFromLastPosition(nullptr)
    ,   mPnlButtons(nullptr)
    ,   mRefSetupModel(refModel)
    ,   mPnlSource(nullptr)
    ,   mPnlTarget(nullptr)
{
    getModel().addObserver(new ResumeFromLastPositionObserver(getResumeFromLastPositionCheckBox()));

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
        {
        mChkResumeFromLastPosition = new QCheckBox("&Resume from Last Position?", this);

        connect(mChkResumeFromLastPosition, &QCheckBox::clicked, this, &SetupPanel::resumeFromLastPositionClicked);
        }

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
