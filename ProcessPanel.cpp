#include "ProcessPanel.h"

using namespace net::draconia::FileCopier::ui;

void ProcessPanel::initControls()
{

}

void ProcessPanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
}

ProcessPanel::ProcessPanel(QWidget *parent)
    :   QWidget(parent)
    ,   mObjProcessModel(nullptr)
    ,   mLblFile(nullptr)
    ,   mLblFilename(nullptr)
    ,   mBarProgress(nullptr)
    ,   mBtnCancel(nullptr)
    ,   mBtnPauseResume(nullptr)
{ }

ProcessPanel::ProcessPanel(QWidget *parent, FileCopierModel &refModel)
    :   QWidget(parent)
    ,   mObjFileCopierModel(refModel)
    ,   mObjProcessModel(nullptr)
    ,   mLblFile(nullptr)
    ,   mLblFilename(nullptr)
    ,   mBarProgress(nullptr)
    ,   mBtnCancel(nullptr)
    ,   mBtnPauseResume(nullptr)
{ }

QPushButton *ProcessPanel::getCancelButton()
{
    if(mBtnCancel == nullptr)
        mBtnCancel = new QPushButton("&Cancel...", this);

    return(mBtnCancel);
}

const FileCopierModel &ProcessPanel::getFileCopierModel() const
{
    return(mObjFileCopierModel);
}

QLabel *ProcessPanel::getFileLabel()
{
    if(mLblFile == nullptr)
        mLblFile = new QLabel("File:");

    return(mLblFile);
}

QLabel *ProcessPanel::getFilenameLabel()
{
    if(mLblFilename == nullptr)
        mLblFilename = new QLabel(this);

    return(mLblFilename);
}

QPushButton *ProcessPanel::getPauseResumeButton()
{
    if(mBtnPauseResume == nullptr)
        mBtnPauseResume = new QPushButton("Start");

    return(mBtnPauseResume);
}

ProcessModel &ProcessPanel::getProcessModel()
{
    return(mObjProcessModel);
}

QProgressBar *ProcessPanel::getProgressBar()
{
    if(mBarProgress == nullptr)
        mBarProgress = new QProgressBar(this);

    return(mBarProgress);
}
