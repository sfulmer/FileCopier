#pragma once

#include "Observer.h"
#include <QList>
#include <QMap>

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            class FileCopierController;

            namespace model
            {
                class ProcessModel : public Observable
                {
                public:
                    class Status
                    {
                        QString msText;
                    public:
                        Status();
                        Status(const QString &sText);
                        Status(const Status &refCopy);

                        const QString &getText() const;

                        const static Status COPYING;
                        const static Status DONE;
                        const static Status PAUSED;
                        const static Status SETUP;
                        const static Status STALLED;
                    };
                private:
                    FileCopierController &mRefController;
                    long mlCurrentPosition;
                    QMap<QString, QList<QString>> mMapFiles;
                    QString msCurrentDirectory, msCurrentFile;
                    Status mObjStatus;
                protected:
                    QMap<QString, QList<QString>> &getFiles() const;
                public:
                    ProcessModel(FileCopierController &refController);
                    ProcessModel(FileCopierController &refController, const QString &sFilename);
                    ProcessModel(const ProcessModel &refCopy);

                    void addDirectory(const QString &sDirectory, const QList<QString> &lstFiles);
                    void exit();
                    FileCopierController &getController() const;
                    QString &getCurrentDirectory() const;
                    QString &getCurrentFile() const;
                    long &getCurrentPosition() const;
                    const QList<QString> &getFilesForDirectory(const QString &sDirectory) const;
                    Status &getStatus() const;
                    void pause();
                    void removeDirecotry(const QString &sDirectory);
                    void removeFileUnderDirectory(const QString &sDirectory, const QString &sFile);
                    void resume();
                    void setCurrentDirectory(const QString &sDirectory);
                    void setCurrentFile(const QString &sFile);
                    void setCurrentPosition(const long &lPosition);
                    void setFilesForDirectory(const QString &sDirectory, const QList<QString> &lstFiles);
                    void setStatus(const Status &refStatus);
                    void startCopying();
                };
            }
        }
    }
}
