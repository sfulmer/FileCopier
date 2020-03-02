#pragma once

#include "Observer.h"
#include <QString>

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace model
            {
                class SourcePanelModel : public Observable
                {
                friend class SourcePanelPathObserver;

                    bool mbDirectory;
                    QString msSourceFile;
                protected:
                    void setDirectory(const bool bDirectory);
                public:
                    SourcePanelModel();
                    SourcePanelModel(const QString &sPath);
                    SourcePanelModel(const SourcePanelModel &refCopy);

                    QString &getSourceFile() const;
                    bool isDirectory() const;
                    void setSourceFile(const QString sPath);
                };
            }
        }
    }
}
