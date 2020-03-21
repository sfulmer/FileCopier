#pragma once

#include "Observer.h"
#include "Persistable.h"
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
                class TargetPanelModel : public Observable, public Persistable, public Setable
                {
                    QString msTargetFilename, msTargetPath;
                protected:
                    virtual Properties prefixWithDividerKey(const Properties &refProperties);
                public:
                    TargetPanelModel();
                    TargetPanelModel(const QString &sPath, const QString &sFilename);
                    TargetPanelModel(const TargetPanelModel &refCopy);

                    QString &getFilename() const;
                    QString &getPath() const;
                    virtual Properties pullSettingsToProperties();
                    void setFilename(const QString &sFilename);
                    void setPath(const QString &sPath);
                    virtual void setUp(const Properties &refProperties);
                };
            }
        }
    }
}
