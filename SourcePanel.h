#pragma once

#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include "SourcePanelModel.h"

using namespace net::draconia::FileCopier::model;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace ui
            {
                class SourcePanel : public QWidget
                {
                    Q_OBJECT

                    QLabel *mLblSource;
                    QLineEdit *mTxtSource;
                    QPushButton *mBtnBrowse;
                    SourcePanelModel &mObjModel;
                protected:
                    void browseForSource();
                    void initControls();
                    void initPanel();
                    void sourceFileChanged();
                public:
                    explicit SourcePanel(QWidget *parent, SourcePanelModel &refModel);

                    QPushButton *getBrowseButton();
                    SourcePanelModel &getModel() const;
                    QLineEdit *getSourceField();
                    QLabel *getSourceLabel();
                signals:
                };
            }
        }
    }
}
