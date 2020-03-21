#pragma once

#include "ProcessModel.h"
#include "Setable.h"
#include "SetupModel.h"

using namespace net::draconia::FileCopier::model;
using net::draconia::util::Properties;
using net::draconia::util::Setable;

namespace net
{
    namespace draconia
    {
        class FileCopierApp;

        namespace FileCopier
        {
            class FileCopierController : public Setable
            {
                bool mbNormalExit;
                FileCopierApp &mRefApp;
                ProcessModel mObjProcessModel;
                SetupModel mObjSetupModel;
            protected:
                QList<QString> collectListOfFilesToMove(const QString &sDir = "");
                FileCopierApp &getApplication();
                void setNormalExit(const bool bNormalExit);
            public:
                FileCopierController(FileCopierApp &refApp);

                ProcessModel &getProcessModel() const;
                SetupModel &getSetupModel() const;

                void cancelProcess();
                void exit(const bool bNormalExit = false);
                bool isNormalExit() const;
                void pauseProcess();
                void resumeProcess();
                virtual void setUp(const Properties &refProperties);
                void startProcess();
            };
        }
    }
}
