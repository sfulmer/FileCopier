#pragma once

#include <QCheckBox>
#include <QWidget>
#include "SetupButtonPanel.h"
#include "SetupModel.h"
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

                    QCheckBox *mChkResumeFromLastPosition;
                    SetupButtonPanel *mPnlButtons;
                    SetupModel &mRefSetupModel;
                    SourcePanel *mPnlSource;
                    TargetPanel *mPnlTarget;
                protected:
                    void initControls();
                    void initPanel();
                    void resumeFromLastPositionClicked();
                public:
                    SetupPanel(QWidget *parent, SetupModel &refSetupModel);

                    SetupButtonPanel *getButtonPanel();
                    SetupModel &getModel() const;
                    QCheckBox *getResumeFromLastPositionCheckBox();
                    SourcePanel *getSourcePanel();
                    TargetPanel *getTargetPanel();
                signals:

                };
            }
        }
    }
}
