#include "FileCopierApp.h"
#include "FileCopierController.h"
#include <iostream>
#include <QDir>
#include <QFileInfo>

using net::draconia::FileCopierApp;
using namespace net::draconia::FileCopier;
using net::draconia::FileCopier::model::ProcessModel;
using net::draconia::FileCopier::model::SetupModel;
using namespace std;

QList<QString> FileCopierController::collectListOfFilesToMove(const QString &sDir)
{
    QDir dirSource;

    dirSource.setSorting(QDir::SortFlag::DirsFirst);

    if(sDir == "")
        dirSource.setPath(getSetupModel().getSourcePanelModel().getSourceFile());
    else
        dirSource.setPath(sDir);

    QList<QString> lstFiles;
    QStringList sFileList = dirSource.entryList();

    for(QString sFile : sFileList)
        {
        cout << sFile.toStdString() << endl;

        if(QFileInfo(sFile).isDir() && !((sFile == ".") || (sFile == "..")))
            lstFiles.append(collectListOfFilesToMove(sFile));
        else
            lstFiles.append(sFile);
        }

    return(lstFiles);
}

FileCopierApp &FileCopierController::getApplication()
{
    return(mRefApp);
}

FileCopierController::FileCopierController(FileCopierApp &refApp)
    :   mRefApp(refApp)
    ,   mObjProcessModel(*this)
    ,   mObjSetupModel(*this)
{ }

SetupModel &FileCopierController::getSetupModel() const
{
    return(const_cast<SetupModel &>(mObjSetupModel));
}

void FileCopierController::cancelProcess()
{
    // TODO Put code in here
}

void FileCopierController::exit()
{
    getApplication().exit();
}

ProcessModel &FileCopierController::getProcessModel() const
{
    return(const_cast<ProcessModel &>(mObjProcessModel));
}

void FileCopierController::pauseProcess()
{
    // TODO Put code in here
}

void FileCopierController::resumeProcess()
{
    //TODO Put code in here
}

void FileCopierController::startProcess()
{
    QList<QString> lstFiles = collectListOfFilesToMove(getSetupModel().getSourcePanelModel().getSourceFile());
}
