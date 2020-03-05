#include "FileCopierController.h"
#include "ProcessModel.h"
#include "SetupModel.h"
#include "StartButtonObserver.h"

using net::draconia::FileCopier::FileCopierController;
using net::draconia::FileCopier::model::ProcessModel;
using net::draconia::FileCopier::model::SetupModel;
using namespace net::draconia::FileCopier::observers;

QPushButton *StartButtonObserver::getStartButton()
{
    return(mBtnStart);
}

StartButtonObserver::StartButtonObserver(QPushButton *btnStart)
    :   Observer()
    ,   mBtnStart(btnStart)
{ }

void StartButtonObserver::update(const Observable &objObservable, const QString &sProperty)
{
    if((sProperty == "SourcePanel") || (sProperty == "TargetPanel") || (sProperty == "Status"))
        {
        QString sTargetFilename;
        ProcessModel *ptrProcessModel;
        SetupModel *ptrSetupModel;

        if((sProperty == "SourcePanel") || (sProperty == "TargetPanel"))
            {
            ptrSetupModel = &static_cast<SetupModel &>(const_cast<Observable &>(objObservable));
            ptrProcessModel = &(ptrSetupModel->getController().getProcessModel());
            }
        else if(sProperty == "Status")
            {
            ptrProcessModel = &static_cast<ProcessModel &>(const_cast<Observable &>(objObservable));
            ptrSetupModel = &(ptrProcessModel->getController().getSetupModel());
            }
        else
            {
            ptrProcessModel = nullptr;
            ptrSetupModel = nullptr;
            }

        if(!(ptrSetupModel == nullptr) || (ptrProcessModel == nullptr))
            {
            sTargetFilename = ptrSetupModel->getTargetPanelModel().getPath() + ptrSetupModel->getTargetPanelModel().getFilename();

            getStartButton()->setEnabled(   (!ptrSetupModel->getSourcePanelModel().getSourceFile().isEmpty())
                                        &&  (!sTargetFilename.isEmpty())
                                        &&  (!(ptrProcessModel->isDone() || ptrProcessModel->isSetup())));
            }
        }
}
