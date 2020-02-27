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
}

void SetupPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));

    initControls();
}

SetupPanel::SetupPanel(QWidget *parent)
    :   QWidget(parent)
{ }

SetupPanel::~SetupPanel()
{ }

QCheckBox *SetupPanel::getResumeFromLastPositionCheckBox()
{
    if(mChkResumeFromLastPosition == nullptr)
        mChkResumeFromLastPosition = new QCheckBox("&Resume from Last Position?", this);

    return(mChkResumeFromLastPosition);
}

SourcePanel *SetupPanel::getSourcePanel() const
{
    return(const_cast<SourcePanel *>(mPnlSource));
}

TargetPanel *SetupPanel::getTargetPanel() const
{
    return(const_cast<TargetPanel *>(mPnlTarget));
}
