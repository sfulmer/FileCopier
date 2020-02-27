#pragma once

#include "FileCopierController.h"
#include "SourcePanelModel.h"
#include "TargetPanelModel.h"

using namespace  net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace model
            {
                class FileCopierModel : public Observable
                {
                    bool mbRestartFromLastPosition;
                    FileCopierController &mRefController;
                    SourcePanelModel mObjSourcePanelModel;
                    TargetPanelModel mObjTargetPanelModel;
                public:
                    FileCopierModel(FileCopierController &refController);
                    FileCopierModel(FileCopierController &refController, const SourcePanelModel &refSourceModel, const TargetPanelModel &refTargetModel);
                    FileCopierModel(const FileCopierModel &refCopy);

                    FileCopierController &getController() const;
                    bool getRestartFromLastPosition() const;
                    SourcePanelModel &getSourcePanelModel() const;
                    TargetPanelModel &getTargetPanelModel() const;
                    void setRestartFromLastPosition(const bool bRestartFromLastPosition);
                };
            }
        }
    }
}
