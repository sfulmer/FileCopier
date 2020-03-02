#include "SetupModel.h"
#include "StartButtonObserver.h"

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
    Q_UNUSED(sProperty);

    QString sTargetFilename;
    SetupModel &refModel = static_cast<SetupModel &>(const_cast<Observable &>(objObservable));

    sTargetFilename = refModel.getTargetPanelModel().getPath() + refModel.getTargetPanelModel().getFilename();

    getStartButton()->setEnabled(   (!refModel.getSourcePanelModel().getSourceFile().isEmpty())
                                &&  (!sTargetFilename.isEmpty()));
}
