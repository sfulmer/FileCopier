#include "TargetPanelObserver.h"

using namespace net::draconia::util;
using net::draconia::FileCopier::model::TargetPanelModel;
using namespace net::draconia::FileCopier::observers;

QLineEdit *TargetPanelObserver::getDirectoryField()
{
    return(mTxtDirectory);
}

QLineEdit *TargetPanelObserver::getFilenameField()
{
    return(mTxtFilename);
}

TargetPanelObserver::TargetPanelObserver(QLineEdit *txtDirectory, QLineEdit *txtFilename)
    :   Observer()
    ,   mTxtDirectory(txtDirectory)
    ,   mTxtFilename(txtFilename)
{ }

void TargetPanelObserver::update(const Observable &refObservable, const QString &sProperty)
{
    TargetPanelModel &objModel = static_cast<TargetPanelModel &>(const_cast<Observable &>(refObservable));

    if((sProperty == "Path") && (objModel.getPath() != getDirectoryField()->text()))
        getDirectoryField()->setText(objModel.getPath());
    if((sProperty == "Filename") && (objModel.getFilename() != getFilenameField()->text()))
        getFilenameField()->setText(objModel.getFilename());
}
