#pragma once

#include "ProcessModel.h"
#include <QLabel>
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
                class ProcessFilenamePanel : public QWidget
                {
                    Q_OBJECT

                    QSharedPointer<ProcessModel> mPtrProcessModel;
                    QLabel *mLblFile, *mLblFilename;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    explicit ProcessFilenamePanel(QWidget *parent = nullptr);
                    ProcessFilenamePanel(QWidget *parent, const ProcessModel &refModel);
                    ~ProcessFilenamePanel();

                    QLabel *getFileLabel();
                    QLabel *getFilenameLabel();
                    ProcessModel &getProcessModel();
                    void setProcessModel(const ProcessModel &refModel);
                signals:

                };
            }
        }
    }
}
