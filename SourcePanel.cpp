#include <QHBoxLayout>
#include <QFileDialog>
#include <QMessageBox>
#include "SourcePanel.h"
#include "SourcePanelObserver.h"

using net::draconia::FileCopier::observers::SourceFileObserver;
using namespace net::draconia::FileCopier::ui;

void SourcePanel::browseForSource()
{
    QFileDialog dlgFile(this, "Browse For Source File|Folder");
    QString sFilename;

    dlgFile.setAcceptMode(QFileDialog::AcceptMode::AcceptOpen);
    dlgFile.setFileMode(QFileDialog::FileMode::Directory);

    if(dlgFile.exec() == QFileDialog::Accepted)
        {
        sFilename = dlgFile.selectedFiles()[0];

        getModel().setSourceFile(sFilename);        }
}

void SourcePanel::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    layout->addWidget(getSourceLabel());
    layout->addWidget(getSourceField());
    layout->addWidget(getBrowseButton());

    setLayout(layout);
}

void SourcePanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));

    initControls();
}

void SourcePanel::sourceFileChanged()
{
    if(getSourceField()->text() != getModel().getSourceFile())
        getModel().setSourceFile(getSourceField()->text());
}

SourcePanel::SourcePanel(QWidget *parent, SourcePanelModel &refModel)
    :   QWidget(parent)
    ,   mLblSource(nullptr)
    ,   mTxtSource(nullptr)
    ,   mBtnBrowse(nullptr)
    ,   mObjModel(refModel)
{
    getModel().addObserver(new SourceFileObserver(getSourceField()));

    initPanel();
}

QPushButton *SourcePanel::getBrowseButton()
{
    if(mBtnBrowse == nullptr)
        {
        mBtnBrowse = new QPushButton("&Browse...", this);

        connect(mBtnBrowse, &QPushButton::clicked, this, &SourcePanel::browseForSource);
        }

    return(mBtnBrowse);
}

SourcePanelModel &SourcePanel::getModel() const
{
    return(mObjModel);
}

QLineEdit *SourcePanel::getSourceField()
{
    if(mTxtSource == nullptr)
        {
        mTxtSource = new QLineEdit(getModel().getSourceFile(), this);

        connect(mTxtSource, &QLineEdit::textChanged, this, &SourcePanel::sourceFileChanged);
        }

    return(mTxtSource);
}

QLabel *SourcePanel::getSourceLabel()
{
    if(mLblSource == nullptr)
        {
        mLblSource = new QLabel("&Source:", this);

        mLblSource->setAutoFillBackground(false);
        mLblSource->setBuddy(getSourceField());
        }

    return(mLblSource);
}
