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
        cout << sDir.toStdString() << "/" << sFile.toStdString() << endl;

        if(QFileInfo(sDir + "/" + sFile).isDir() && !((sFile == ".") || (sFile == "..")))
            lstFiles.append(collectListOfFilesToMove(sDir + "/" + sFile));
        else
            lstFiles.append(sDir + "/" + sFile);
        }

    return(lstFiles);
}

FileCopierApp &FileCopierController::getApplication()
{
    return(mRefApp);
}

void FileCopierController::setNormalExit(const bool bNormalExit)
{
    mbNormalExit = bNormalExit;
}

FileCopierController::FileCopierController(FileCopierApp &refApp)
    :   mbNormalExit(false)
    ,   mRefApp(refApp)
    ,   mObjProcessModel(*this)
    ,   mObjSetupModel(*this)
{ }

SetupModel &FileCopierController::getSetupModel() const
{
    return(const_cast<SetupModel &>(mObjSetupModel));
}

void FileCopierController::exit(const bool bNormalExit)
{
    setNormalExit(bNormalExit);

    getApplication().exit();
}

ProcessModel &FileCopierController::getProcessModel() const
{
    return(const_cast<ProcessModel &>(mObjProcessModel));
}

bool FileCopierController::isNormalExit() const
{
    return(mbNormalExit);
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
    for(QString sFile : collectListOfFilesToMove(getSetupModel().getSourcePanelModel().getSourceFile()))
        getProcessModel().addFile(sFile);

    getProcessModel().start();
}
