#include <QHBoxLayout>
#include "TargetPanel.h"

using namespace net::draconia::FileCopier::ui;

void TargetPanel::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    setLayout(layout);

    layout->addWidget(getTargetLabel());
    layout->addWidget(getTargetPathField());
    layout->addWidget(getSeparatorLabel());
    layout->addWidget(getTargetFileField());
    layout->addWidget(getBrowseButton());
}

void TargetPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));

    initControls();
}

TargetPanel::TargetPanel(QWidget *parent, TargetPanelModel &refModel)
    :   QWidget(parent)
    ,   mLblSeparator(nullptr)
    ,   mLblTarget(nullptr)
    ,   mTxtTargetFile(nullptr)
    ,   mTxtTargetPath(nullptr)
    ,   mBtnBrowse(nullptr)
    ,   mObjModel(refModel)
{
    initPanel();
}

QPushButton *TargetPanel::getBrowseButton()
{
    if(mBtnBrowse == nullptr)
        mBtnBrowse = new QPushButton("&Browse...", this);

    return(mBtnBrowse);
}

TargetPanelModel &TargetPanel::getModel() const
{
    return(mObjModel);
}

QLabel *TargetPanel::getSeparatorLabel()
{
    if(mLblSeparator == nullptr)
        {
        mLblSeparator = new QLabel(" / ", this);

        mLblSeparator->setAutoFillBackground(false);
        mLblSeparator->setFont(QFont(font().family(), font().pointSize(), QFont::Bold));
        }

    return(mLblSeparator);
}

QLineEdit *TargetPanel::getTargetFileField()
{
    if(mTxtTargetFile == nullptr)
        mTxtTargetFile = new QLineEdit(this);

    return(mTxtTargetFile);
}

QLabel *TargetPanel::getTargetLabel()
{
    if(mLblTarget == nullptr)
        {
        mLblTarget = new QLabel("&Target:", this);

        mLblTarget->setBuddy(getTargetPathField());
        mLblTarget->setAutoFillBackground(false);
        mLblTarget->setFont(QFont(font().family(), font().pointSize(), QFont::Bold));
        }

    return(mLblTarget);
}

QLineEdit *TargetPanel::getTargetPathField()
{
    if(mTxtTargetPath == nullptr)
        mTxtTargetPath = new QLineEdit(this);

    return(mTxtTargetPath);
}
