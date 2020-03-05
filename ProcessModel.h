#pragma once

#include <fstream>
#include <iostream>
#include "Observer.h"
#include <QList>
#include <QMap>

using namespace net::draconia::util;
using namespace std;

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
                    protected:
                        void setText(const QString &sText);
                    public:
                        Status();
                        Status(const QString &sText);
                        Status(const Status &refCopy);

                        const QString &getText() const;

                        bool operator==(const Status &refOther) const;
                        bool operator!=(const Status &refOther) const;
                        Status &operator=(const Status &refCopy);

                        const static Status DONE;
                        const static Status MOVING;
                        const static Status PAUSED;
                        const static Status SETUP;
                        const static Status STALLED;
                    };
                private:
                    char mcBuffer[1024];
                    FileCopierController &mRefController;
                    ifstream mObjIn;
                    int miBufferReadSize, miBufferSize;
                    long mlCurrentPosition;
                    ofstream mObjOut;
                    qint64 miCurrentBytesMoved, miTotalBytesToMove;
                    QList<QString> mLstFiles;
                    QString msCurrentFile;
                    Status &mObjStatus;
                protected:
                    qint64 calculateTotalBytesToMove() const;
                    char *getBuffer();
                    int getBufferReadSize() const;
                    int getBufferSize() const;
                    QList<QString> &getFiles() const;
                    ifstream &getInputFile();
                    ofstream &getOutputFile();
                    bool isDirectoryEmptyForFile(const QString &sFile) const;
                    void moveFile(const QString sSource, const QString sTarget);
                    void removeDirectory(const QString sDirectory);
                    void removeFile(const QString &sFile);
                    void setBufferReadSize(const int iBufferReadSize);
                    void setBufferSize(const int iBufferSize);
                    void setCurrentBytesMoved(const qint64 iCurrentBytesMoved);
                    void setCurrentFile(const QString &sFile);
                    void setCurrentPosition(const long &lPosition);
                    void setStatus(const Status &refStatus);
                    void setTotalBytesToMove(const qint64 iTotalBytesToMove);
                public:
                    ProcessModel(FileCopierController &refController);
                    ProcessModel(const ProcessModel &refCopy);

                    void addFile(const QString &sFile);
                    void exit();
                    FileCopierController &getController() const;
                    qint64 getCurrentBytesMoved() const;
                    QString &getCurrentFile() const;
                    long &getCurrentPosition() const;
                    const QList<QString> &getFilesToMove() const;
                    Status &getStatus() const;
                    qint64 getTotalBytesToMove();
                    bool isDone() const;
                    bool isMoving() const;
                    bool isPaused() const;
                    bool isSetup() const;
                    bool isStalled() const;
                    void pause();
                    void resume();
                    void setFilesToMove(const QList<QString> &lstFiles);
                    void start();
                };
            }
        }
    }
}
