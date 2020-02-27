#pragma once

#include "FileCopierModel.h"
#include <QCheckBox>
#include <QWidget>
#include "SetupButtonPanel.h"
#include "SourcePanel.h"
#include "TargetPanel.h"

using namespace net::draconia::FileCopier::model;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace ui
            {
                class SetupPanel : public QWidget
                {
                    Q_OBJECT

                    FileCopierModel &mRefSetupModel;
                    QCheckBox *mChkResumeFromLastPosition;
                    SetupButtonPanel *mPnlButtons;
                    SourcePanel *mPnlSource;
                    TargetPanel *mPnlTarget;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    SetupPanel(QWidget *parent, FileCopierModel &refSetupModel);

                    SetupButtonPanel *getButtonPanel();
                    FileCopierModel &getModel() const;
                    QCheckBox *getResumeFromLastPositionCheckBox();
                    SourcePanel *getSourcePanel();
                    TargetPanel *getTargetPanel();
                signals:

                };
            }
        }
    }
}
