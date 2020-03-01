#pragma once

#include "ProcessModel.h"
#include "SetupModel.h"

using namespace net::draconia::FileCopier::model;

namespace net
{
    namespace draconia
    {
        class FileCopierApp;

        namespace FileCopier
        {
            class FileCopierController
            {
                FileCopierApp &mRefApp;
                ProcessModel mObjProcessModel;
                SetupModel mObjSetupModel;
            protected:
                FileCopierApp &getApplication();
            public:
                FileCopierController(FileCopierApp &refApp);

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
