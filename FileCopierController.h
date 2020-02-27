#pragma once

#include "FileCopierModel.h"
#include "ProcessModel.h"

using namespace net::draconia::FileCopier::model;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            class FileCopierController
            {
                FileCopierModel mObjSetupModel;
                ProcessModel mObjProcessModel;
            public:
                FileCopierController();

                FileCopierModel &getSetupModel() const;
                ProcessModel &getProcessModel() const;

                void cancelProcess();
                void pauseProcess();
                void resumeProcess();
                void startProcess();
            };
        }
    }
}
