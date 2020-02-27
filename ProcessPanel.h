#pragma once

#include "FileCopierModel.h"
#include "ProcessButtonPanel.h"
#include "ProcessModel.h"
#include "ProcessFilenamePanel.h"
#include <QProgressBar>
#include <QPushButton>
#include <QSharedPointer>
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

                    QSharedPointer<FileCopierModel> mPtrFileCopierModel;
                    ProcessButtonPanel *mPnlButtons;
                    ProcessFilenamePanel *mPnlFilename;
                    ProcessModel mObjProcessModel;
                    QProgressBar *mBarProgress;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    explicit ProcessPanel(QWidget *parent = nullptr);
                    ProcessPanel(QWidget *parent, FileCopierModel &refModel);

                    ProcessButtonPanel *getButtonPanel();
                    const FileCopierModel &getFileCopierModel() const;
                    ProcessFilenamePanel *getFilenamePanel();
                    ProcessModel &getProcessModel();
                    QProgressBar *getProgressBar();
                signals:

                };
            }
        }
    }
}
