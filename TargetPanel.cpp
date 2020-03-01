#include <QFileDialog>
#include <QHBoxLayout>
#include "TargetPanel.h"
#include "TargetPanelObserver.h"

using net::draconia::FileCopier::observers::TargetPanelObserver;
using namespace net::draconia::FileCopier::ui;

void TargetPanel::browseForTarget()
{
    QFileDialog dlgFile(this, "Select Target Folder");

    dlgFile.setFileMode(QFileDialog::FileMode::Directory);

    if(dlgFile.exec() == QFileDialog::Accepted)
        {
        QFileInfo fileSelected(dlgFile.selectedFiles()[0]);
        QString sPath, sFilename;

        getModel().setPath(fileSelected.absolutePath());
        getModel().setFilename(fileSelected.fileName());
        }
}

void TargetPanel::fileFieldChanged()
{
    if(getTargetFileField()->text() != getModel().getFilename())
        getModel().setFilename(getTargetFileField()->text());
}

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

void TargetPanel::pathFieldChanged()
{
    if(getTargetPathField()->text() != getModel().getPath())
        getModel().setPath(getTargetPathField()->text());
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
    mObjModel.addObserver(new TargetPanelObserver(getTargetPathField(), getTargetFileField()));

    initPanel();
}

QPushButton *TargetPanel::getBrowseButton()
{
    if(mBtnBrowse == nullptr)
        {
        mBtnBrowse = new QPushButton("&Browse...", this);

        connect(mBtnBrowse, &QPushButton::clicked, this, &TargetPanel::browseForTarget);
        }

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
        {
        mTxtTargetFile = new QLineEdit(this);

        connect(mTxtTargetFile, &QLineEdit::textChanged, this, &TargetPanel::fileFieldChanged);
        }

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
        {
        mTxtTargetPath = new QLineEdit(this);

        connect(mTxtTargetPath, &QLineEdit::textChanged, this, &TargetPanel::pathFieldChanged);
        }

    return(mTxtTargetPath);
}
