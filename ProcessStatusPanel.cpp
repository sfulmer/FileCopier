#include "ProcessStatusPanel.h"
#include <QHBoxLayout>

using namespace net::draconia::FileCopier::ui;

void ProcessStatusPanel::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    setLayout(layout);

    layout->addWidget(getStatusLabel());
    layout->addWidget(getStatusText());
}

void ProcessStatusPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));

    initControls();
}

ProcessStatusPanel::ProcessStatusPanel(QWidget *parent, ProcessModel &refModel)
    :   QWidget(parent)
    ,   mRefModel(refModel)
    ,   mLblStatus(nullptr)
    ,   mLblStatusText(nullptr)
{
    initPanel();
}

ProcessModel &ProcessStatusPanel::getModel()
{
    return(mRefModel);
}

QLabel *ProcessStatusPanel::getStatusLabel()
{
    if(mLblStatus == nullptr)
        {
        mLblStatus = new QLabel("Status: ", this);

        mLblStatus->setAutoFillBackground(false);
        }

    return(mLblStatus);
}

QLabel *ProcessStatusPanel::getStatusText()
{
    if(mLblStatusText == nullptr)
        {
        mLblStatusText = new QLabel(getModel().getStatus().getText(), this);

        mLblStatusText->setAutoFillBackground(false);
        }

    return(mLblStatusText);
}
