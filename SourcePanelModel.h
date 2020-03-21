#pragma once

#include "Observer.h"
#include "Persistable.h"
#include <QString>
#include "Setable.h"

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace model
            {
                class SourcePanelModel : public Observable, public Persistable, public Setable
                {
                friend class SourcePanelPathObserver;

                    bool mbDirectory;
                    QString msSourceFile;
                protected:
                    virtual Properties prefixWithDividerKey(const Properties &refProperties);
                    void setDirectory(const bool bDirectory);
                public:
                    SourcePanelModel();
                    SourcePanelModel(const QString &sPath);
                    SourcePanelModel(const SourcePanelModel &refCopy);

                    QString &getSourceFile() const;
                    bool isDirectory() const;
                    virtual Properties pullSettingsToProperties();
                    void setSourceFile(const QString sPath);
                    virtual void setUp(const Properties &refProperties);
                };
            }
        }
    }
}
