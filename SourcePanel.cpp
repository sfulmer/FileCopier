#include <QHBoxLayout>
#include "SourcePanel.h"

using namespace net::draconia::FileCopier::ui;

void SourcePanel::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    layout->addWidget(getSourceLabel());
    layout->addWidget(getSourceField());
    layout->addWidget(getBrowseButton());
}

void SourcePanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));

    initControls();
}

SourcePanel::SourcePanel(QWidget *parent, SourcePanelModel &refModel)
    :   QWidget(parent)
    ,   mLblSource(nullptr)
    ,   mTxtSource(nullptr)
    ,   mBtnBrowse(nullptr)
    ,   mObjModel(refModel)
{
    initPanel();
}

QPushButton *SourcePanel::getBrowseButton()
{
    if(mBtnBrowse == nullptr)
        mBtnBrowse = new QPushButton("&Browse...", this);

    return(mBtnBrowse);
}

SourcePanelModel &SourcePanel::getModel() const
{
    return(mObjModel);
}

QLineEdit *SourcePanel::getSourceField()
{
    if(mTxtSource == nullptr)
        mTxtSource = new QLineEdit(this);

    return(mTxtSource);
}

QLabel *SourcePanel::getSourceLabel()
{
    if(mLblSource == nullptr)
        mLblSource = new QLabel("&Source:", this);

    return(mLblSource);
}
