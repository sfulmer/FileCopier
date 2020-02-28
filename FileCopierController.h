#pragma once

#include "ProcessModel.h"
#include "SetupModel.h"

using namespace net::draconia::FileCopier::model;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            class FileCopierController
            {
               ProcessModel mObjProcessModel;
               SetupModel mObjSetupModel;
            public:
                FileCopierController();

                ProcessModel &getProcessModel() const;
                SetupModel &getSetupModel() const;

                void cancelProcess();
                void exit();
                void pauseProcess();
                void resumeProcess();
                void startProcess();
            };
        }
    }
}
