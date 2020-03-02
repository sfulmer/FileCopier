#include <QHBoxLayout>
#include "SetupButtonPanel.h"
#include "StartButtonObserver.h"

using net::draconia::FileCopier::FileCopierController;
using net::draconia::FileCopier::observers::StartButtonObserver;
using namespace net::draconia::FileCopier::ui;

void SetupButtonPanel::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    setLayout(layout);

    layout->addWidget(getStartButton());
}

void SetupButtonPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));

    initControls();
}

void SetupButtonPanel::startButtonClicked()
{
    getController().startProcess();
}

SetupButtonPanel::SetupButtonPanel(QWidget *parent, FileCopierController &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
    ,   mBtnStart(nullptr)
{
    getController().getSetupModel().addObserver(new StartButtonObserver(getStartButton()));

    initPanel();
}

FileCopierController &SetupButtonPanel::getController() const
{
    return(const_cast<FileCopierController &>(mRefController));
}

QPushButton *SetupButtonPanel::getStartButton()
{
    if(mBtnStart == nullptr)
        {
        mBtnStart = new QPushButton("&Start", this);

        connect(mBtnStart, &QPushButton::clicked, this, &SetupButtonPanel::startButtonClicked);

        mBtnStart->setDisabled(true);
        }

    return(mBtnStart);
}
