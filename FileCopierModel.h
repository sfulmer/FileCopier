#pragma once

#include "SourcePanelModel.h"
#include "TargetPanelModel.h"
#include <vector>

using namespace  net::draconia::util;
using namespace std;

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
                    SourcePanelModel mObjSourcePanelModel;
                    TargetPanelModel mObjTargetPanelModel;
                public:
                    FileCopierModel();
                    FileCopierModel(const SourcePanelModel &refSourceModel, const TargetPanelModel &refTargetModel);
                    FileCopierModel(const FileCopierModel &refCopy);

                    bool getRestartFromLastPosition() const;
                    SourcePanelModel &getSourcePanelModel() const;
                    TargetPanelModel &getTargetPanelModel() const;
                    void setRestartFromLastPosition(const bool bRestartFromLastPosition);
                };
            }
        }
    }
}
