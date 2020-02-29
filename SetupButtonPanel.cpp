#include <QHBoxLayout>
#include "SetupButtonPanel.h"

using net::draconia::FileCopier::FileCopierController;
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

SetupButtonPanel::SetupButtonPanel(QWidget *parent, FileCopierController &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
    ,   mBtnStart(nullptr)
{
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

        mBtnStart->setDisabled(true);
        }

    return(mBtnStart);
}
