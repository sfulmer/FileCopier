#pragma once

#include "Observer.h"

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace model
            {
                class TargetPanelModel : public Observable
                {
                    QString msTargetFilename, msTargetPath;
                public:
                    TargetPanelModel();
                    TargetPanelModel(const QString &sPath, const QString &sFilename);
                    TargetPanelModel(const TargetPanelModel &refCopy);

                    QString &getFilename() const;
                    QString &getPath() const;
                    void setFilename(const QString &sFilename);
                    void setPath(const QString &sPath);
                };
            }
        }
    }
}
