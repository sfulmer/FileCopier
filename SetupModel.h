#pragma once

//#include "FileCopierController.h"
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
                class SetupModel : public Observable
                {
                    bool mbResumeFromLastPosition;
                    FileCopierController &mRefController;
                    SourcePanelModel mObjSourcePanelModel;
                    TargetPanelModel mObjTargetPanelModel;
                public:
                    SetupModel(FileCopierController &refController);
                    SetupModel(FileCopierController &refController, const SourcePanelModel &refSourceModel, const TargetPanelModel &refTargetModel);
                    SetupModel(const SetupModel &refCopy);

                    FileCopierController &getController() const;
                    bool getResumeFromLastPosition() const;
                    SourcePanelModel &getSourcePanelModel() const;
                    TargetPanelModel &getTargetPanelModel() const;
                    void setResumeFromLastPosition(const bool bRestartFromLastPosition);
                };
            }
        }
    }
}
