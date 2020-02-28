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

                    ProcessModel &mRefProcessModel;
                    QLabel *mLblFile, *mLblFilename;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    ProcessFilenamePanel(QWidget *parent, const ProcessModel &refModel);

                    QLabel *getFileLabel();
                    QLabel *getFilenameLabel();
                    ProcessModel &getProcessModel();
                signals:

                };
            }
        }
    }
}
