#pragma once

#include <QCheckBox>
#include <QWidget>
#include "SourcePanel.h"
#include "TargetPanel.h"

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
                    SourcePanel *mPnlSource;
                    TargetPanel *mPnlTarget;
                protected:
                    void initControls();
                    void initPanel();
                public:
                    explicit SetupPanel(QWidget *parent = nullptr);
                    ~SetupPanel();

                    QCheckBox *getResumeFromLastPositionCheckBox();
                    SourcePanel *getSourcePanel() const;
                    TargetPanel *getTargetPanel() const;
                signals:

                };
            }
        }
    }
}
