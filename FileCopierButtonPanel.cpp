#include "FileCopierButtonPanel.h"
#include <QHBoxLayout>

using net::draconia::FileCopier::FileCopierController;
using namespace net::draconia::FileCopier::ui;

void FileCopierButtonPanel::exitApplication()
{
    getController().exit();
}

void FileCopierButtonPanel::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    layout->addWidget(getExitButton());

    setLayout(layout);
}

void FileCopierButtonPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));

    initControls();
}

FileCopierButtonPanel::FileCopierButtonPanel(QWidget *parent, FileCopierController &refController)
    :   QWidget(parent)
    ,   mRefController(refController)
    ,   mBtnExit(nullptr)
{
    initPanel();
}

QPushButton *FileCopierButtonPanel::getExitButton()
{
    if(mBtnExit == nullptr)
        {
        mBtnExit = new QPushButton("E&xit", this);

        connect(mBtnExit, &QPushButton::clicked, this, &FileCopierButtonPanel::exitApplication);
        }

    return(mBtnExit);
}

FileCopierController &FileCopierButtonPanel::getController()
{
    return(mRefController);
}
