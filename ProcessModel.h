#pragma once

#include "FileCopierController.h"
#include "Observer.h"
#include <QDir>
#include <QFileInfo>
#include <QList>
#include <QMap>

using namespace net::draconia::util;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
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
                    QDir mDirCurrent;
                    QFile mObjCurrentFile;
                    Status mObjStatus;
                    QMap<QDir, QList<QFile>> mMapFiles;
                protected:
                    QMap<QDir, QList<QFile>> &getFiles() const;
                public:
                    ProcessModel(FileCopierController &refController);
                    ProcessModel(FileCopierController &refController, const QDir &dirCurrent);
                    ProcessModel(FileCopierController &refController, const QFile &objFile);
                    ProcessModel(FileCopierController &refController, const QFileInfo &objFile);
                    ProcessModel(FileCopierController &refController, const QString &sFilename);
                    ProcessModel(const ProcessModel &refCopy);

                    void addDirectory(const QDir &refDirectory, const QList<QFile> &lstFiles);
                    FileCopierController &getController() const;
                    QDir &getCurrentDirectory() const;
                    QFile &getCurrentFile() const;
                    long &getCurrentPosition() const;
                    const QList<QFile> &getFilesForDirectory(const QDir &refDirectory) const;
                    Status &getStatus() const;
                    void pause();
                    void removeDirecotry(const QDir &refDirectory);
                    void removeFileUnderDirectory(const QDir &refDirectory, const QFile &sFile);
                    void removeFileUnderDirectory(const QDir &refDirectory, const QString &sFile);
                    void resume();
                    void setCurrentDirectory(const QDir &refDirectory);
                    void setCurrentFile(const QFile &objFile);
                    void setCurrentFile(const QString &sFile);
                    void setCurrentPosition(const long &lPosition);
                    void setFilesForDirectory(const QDir &refDirectory, const QList<QFile> &lstFiles);
                    void setStatus(const Status &refStatus);
                    void startCopying();
                };
            }
        }
    }
}
