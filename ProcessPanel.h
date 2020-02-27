#pragma once

#include "FileCopierModel.h"
#include "ProcessModel.h"
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>
#include <QWidget>

using namespace net::draconia::FileCopier::model;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace ui
            {
                class ProcessPanel : public QWidget
                {
                    Q_OBJECT

                    FileCopierModel mObjFileCopierModel;
                    ProcessModel mObjProcessModel;
                    QLabel *mLblFile, *mLblFilename;
                    QProgressBar *mBarProgress;
                    QPushButton *mBtnCancel, *mBtnPauseResume;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    explicit ProcessPanel(QWidget *parent = nullptr);
                    ProcessPanel(QWidget *parent, FileCopierModel &refModel);

                    QPushButton *getCancelButton();
                    const FileCopierModel &getFileCopierModel() const;
                    QLabel *getFileLabel();
                    QLabel *getFilenameLabel();
                    QPushButton *getPauseResumeButton();
                    ProcessModel &getProcessModel();
                    QProgressBar *getProgressBar();
                signals:

                };
            }
        }
    }
}
