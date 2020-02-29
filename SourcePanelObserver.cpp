#include "SourcePanelModel.h"
#include "SourcePanelObserver.h"

using net::draconia::FileCopier::model::SourcePanelModel;
using namespace net::draconia::FileCopier::observers;
using namespace net::draconia::util;

QLineEdit *SourceFileObserver::getFieldToEdit()
{
    return(mTxtFieldTOEdit);
}

SourceFileObserver::SourceFileObserver(QLineEdit *txtFieldToEdit)
    :   Observer()
    ,   mTxtFieldTOEdit(txtFieldToEdit)
{ }

void SourceFileObserver::update(const Observable &refObservable, const QString &sProperty)
{
    if(sProperty == "SourceFile")
        {
        SourcePanelModel &objModel = static_cast<SourcePanelModel &>(const_cast<Observable &>(refObservable));

        if(getFieldToEdit()->text() != objModel.getSourceFile())
            getFieldToEdit()->setText(objModel.getSourceFile());
        }
}
