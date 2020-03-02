#pragma once

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
                class SetupModel : public Observable, public Observer
                {
                    bool mbExitWhenDone, mbResumeFromLastPosition;
                    FileCopierController &mRefController;
                    SourcePanelModel mObjSourcePanelModel;
                    TargetPanelModel mObjTargetPanelModel;
                public:
                    SetupModel(FileCopierController &refController);
                    SetupModel(FileCopierController &refController, const SourcePanelModel &refSourceModel, const TargetPanelModel &refTargetModel);
                    SetupModel(const SetupModel &refCopy);

                    FileCopierController &getController() const;
                    bool getExitWhenDone() const;
                    bool getResumeFromLastPosition() const;
                    SourcePanelModel &getSourcePanelModel() const;
                    TargetPanelModel &getTargetPanelModel() const;
                    void setExitWhenDone(const bool bExitWhenDone);
                    void setResumeFromLastPosition(const bool bRestartFromLastPosition);
                    virtual void update(const Observable &objObservable, const QString &sProperty);
                };
            }
        }
    }
}
