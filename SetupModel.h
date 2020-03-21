#pragma once

#include "Persistable.h"
#include "Setable.h"
#include "SourcePanelModel.h"
#include "TargetPanelModel.h"

using namespace  net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            class FileCopierController;

            namespace model
            {
                class SetupModel : public Observable, public Observer, public Persistable, public Setable
                {
                    bool mbExitWhenDone, mbResumeFromLastPosition;
                    FileCopierController &mRefController;
                    SourcePanelModel mObjSourcePanelModel;
                    TargetPanelModel mObjTargetPanelModel;
                protected:
                    virtual Properties prefixWithDividerKey(const Properties &refProperties);
                public:
                    SetupModel(FileCopierController &refController);
                    SetupModel(FileCopierController &refController, const SourcePanelModel &refSourceModel, const TargetPanelModel &refTargetModel);
                    SetupModel(const SetupModel &refCopy);

                    FileCopierController &getController() const;
                    bool getExitWhenDone() const;
                    bool getResumeFromLastPosition() const;
                    SourcePanelModel &getSourcePanelModel() const;
                    TargetPanelModel &getTargetPanelModel() const;
                    virtual Properties pullSettingsToProperties();
                    void setExitWhenDone(const bool bExitWhenDone);
                    void setResumeFromLastPosition(const bool bRestartFromLastPosition);
                    virtual void setUp(const Properties &refProperties);
                    virtual void update(const Observable &objObservable, const QString &sProperty);
                };
            }
        }
    }
}
