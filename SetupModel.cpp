#include "FileCopierController.h"
#include "SetupModel.h"

using net::draconia::FileCopier::FileCopierController;
using namespace net::draconia::FileCopier::model;
using namespace net::draconia::util;

Properties SetupModel::prefixWithDividerKey(const Properties &refProperties)
{
    Properties objReturn;

    for(Property objProperty : refProperties)
        objReturn.add(Property("Setup." + objProperty.getKey(), objProperty.getValue()));

    return(objReturn);
}

SetupModel::SetupModel(FileCopierController &refController)
    :   Observable()
    ,   mbExitWhenDone(true)
    ,   mbResumeFromLastPosition(true)
    ,   mRefController(refController)
{
    getSourcePanelModel().addObserver(this);
    getTargetPanelModel().addObserver(this);
}

SetupModel::SetupModel(FileCopierController &refController, const SourcePanelModel &refSourceModel, const TargetPanelModel &refTargetModel)
    :   Observable()
    ,   mbExitWhenDone(true)
    ,   mbResumeFromLastPosition(true)
    ,   mRefController(refController)
    ,   mObjSourcePanelModel(refSourceModel)
    ,   mObjTargetPanelModel(refTargetModel)
{
    getSourcePanelModel().addObserver(this);
    getTargetPanelModel().addObserver(this);
}

SetupModel::SetupModel(const SetupModel &refCopy)
    :   Observable(refCopy)
    ,   mbExitWhenDone(refCopy.getExitWhenDone())
    ,   mbResumeFromLastPosition(refCopy.getResumeFromLastPosition())
    ,   mRefController(refCopy.getController())
    ,   mObjSourcePanelModel(refCopy.getSourcePanelModel())
    ,   mObjTargetPanelModel(refCopy.getTargetPanelModel())
{
    getSourcePanelModel().addObserver(this);
    getTargetPanelModel().addObserver(this);
}

FileCopierController &SetupModel::getController() const
{
    return(const_cast<FileCopierController &>(mRefController));
}

bool SetupModel::getExitWhenDone() const
{
    return(mbExitWhenDone);
}

bool SetupModel::getResumeFromLastPosition() const
{
    return(mbResumeFromLastPosition);
}

SourcePanelModel &SetupModel::getSourcePanelModel() const
{
    return(const_cast<SourcePanelModel &>(mObjSourcePanelModel));
}

TargetPanelModel &SetupModel::getTargetPanelModel() const
{
    return(const_cast<TargetPanelModel &>(mObjTargetPanelModel));
}

Properties SetupModel::pullSettingsToProperties()
{
    Properties objProperties;

    objProperties.add(prefixWithDividerKey(getSourcePanelModel().pullSettingsToProperties()));
    objProperties.add(prefixWithDividerKey(getTargetPanelModel().pullSettingsToProperties()));
    objProperties.add(Property("Setup.ExitWhenDone", getExitWhenDone() ? "True" : "False"));
    objProperties.add(Property("Setup.ResumeFromLastPosition", getResumeFromLastPosition() ? "True" : "False"));

    return(objProperties);
}

void SetupModel::setExitWhenDone(const bool bExitWhenDone)
{
    mbExitWhenDone = bExitWhenDone;

    setChanged();
    notifyObservers("ExitWhenDone");
}

void SetupModel::setResumeFromLastPosition(const bool bResumeFromLastPosition)
{
    mbResumeFromLastPosition = bResumeFromLastPosition;

    setChanged();
    notifyObservers("ResumeFromLastPosition");
}

void SetupModel::setUp(const Properties &refProperties)
{
    Properties objSourceProperties, objTargetProperties;

    for(Property objProperty : refProperties)
        {
        QString sDividerKey, sNewKey, sValue;
        QStringList sPropertyKeyParts = objProperty.getKey().split(".");

        sDividerKey = sPropertyKeyParts[0];
        sPropertyKeyParts.removeAt(0);
        sNewKey = sPropertyKeyParts.join(".");
        sValue = objProperty.getValue();

        if(sDividerKey.toUpper() == "SOURCE")
            objSourceProperties.add(Property(sNewKey, sValue));
        else if(sDividerKey.toUpper() == "TARGET")
            objTargetProperties.add(Property(sNewKey, sValue));
        else if(sDividerKey.toUpper() == "EXITWHENDONE")
            setExitWhenDone(objProperty.getValue().toUpper() == "TRUE");
        else if(sDividerKey.toUpper() == "RESUMEFROMLASTPOSITION")
            setResumeFromLastPosition(objProperty.getValue().toUpper() == "TRUE");
        }

    getSourcePanelModel().setUp(objSourceProperties);
    getTargetPanelModel().setUp(objTargetProperties);
}

void SetupModel::update(const Observable &objObservable, const QString &sProperty)
{
    Q_UNUSED(objObservable);

    setChanged();

    if(sProperty.contains("Source"))
        notifyObservers("Source");
    else
        notifyObservers("Target");
}
