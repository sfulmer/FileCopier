#include "ProcessCurrentFileObserver.h"
#include "ProcessFilenamePanel.h"
#include <QHBoxLayout>

using net::draconia::FileCopier::observers::ProcessCurrentFileObserver;
using namespace net::draconia::FileCopier::ui;

void ProcessFilenamePanel::initControls()
{
    QLayout *layout = new QHBoxLayout(this);

    setLayout(layout);

    layout->addWidget(getFileLabel());
    layout->addWidget(getFilenameLabel());
}

void ProcessFilenamePanel::initPanel()
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));

    initControls();
}

ProcessFilenamePanel::ProcessFilenamePanel(QWidget *parent, const ProcessModel &refModel)
    :   QWidget(parent)
    ,   mRefProcessModel(const_cast<ProcessModel &>(refModel))
    ,   mLblFile(nullptr)
    ,   mLblFilename(nullptr)
{
    getProcessModel().addObserver(new ProcessCurrentFileObserver(getFilenameLabel()));

    initPanel();
}

QLabel *ProcessFilenamePanel::getFileLabel()
{
    if(mLblFile == nullptr)
        {
        mLblFile = new QLabel("File: ", this);

        mLblFile->setAutoFillBackground(false);
        }

    return(mLblFile);
}

QLabel *ProcessFilenamePanel::getFilenameLabel()
{
    if(mLblFilename == nullptr)
        {
        QString sFilename = getProcessModel().getCurrentFile();

        if(sFilename == "")
            sFilename = "N/A";

        mLblFilename = new QLabel(sFilename, this);

        mLblFilename->setAutoFillBackground(false);
        }

    return(mLblFilename);
}

ProcessModel &ProcessFilenamePanel::getProcessModel()
{
    return(mRefProcessModel);
}
