#include "FileCopierApp.h"
#include "FileCopierController.h"
#include <iostream>
#include <QDir>
#include <QFileInfo>
#include "StatusDoneObserver.h"

using net::draconia::FileCopierApp;
using namespace net::draconia::FileCopier;
using net::draconia::FileCopier::model::ProcessModel;
using net::draconia::FileCopier::model::SetupModel;
using net::draconia::FileCopier::observers::StatusDoneObserver;
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
{
    getProcessModel().addObserver(new StatusDoneObserver());
}

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
    getProcessModel().pause();
}

void FileCopierController::resumeProcess()
{
    getProcessModel().resume();
}

void FileCopierController::setUp(const Properties &refProperties)
{
    Properties objSetupProperties;

    for(Property objProperty : refProperties)
        {
        QString sDividerKey, sNewKey, sValue;
        QStringList sPropertyKeyParts = objProperty.getKey().split(".");

        sDividerKey = sPropertyKeyParts[0];
        sPropertyKeyParts.removeAt(0);
        sNewKey = sPropertyKeyParts.join(".");
        sValue = objProperty.getValue();

        if(sDividerKey.toUpper() == "SETUP")
            objSetupProperties.add(Property(sNewKey, sValue));
        }

    getSetupModel().setUp(objSetupProperties);

}

void FileCopierController::startProcess()
{
    for(QString sFile : collectListOfFilesToMove(getSetupModel().getSourcePanelModel().getSourceFile()))
        getProcessModel().addFile(sFile);

    getProcessModel().start();
}
