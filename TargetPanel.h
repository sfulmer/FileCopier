#pragma once

#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QWidget>
#include "TargetPanelModel.h"

using namespace net::draconia::FileCopier::model;

namespace net
{
    namespace draconia
    {
        namespace FileCopier
        {
            namespace ui
            {
                class TargetPanel : public QWidget
                {
                    Q_OBJECT
                    QLabel *mLblSeparator, *mLblTarget;
                    QLineEdit *mTxtTargetFile, *mTxtTargetPath;
                    QPushButton *mBtnBrowse;
                    TargetPanelModel &mObjModel;
                protected:
                    void browseForTarget();
                    void fileFieldChanged();
                    void initControls();
                    void initPanel();
                    void pathFieldChanged();
                public:
                    TargetPanel(QWidget *parent, TargetPanelModel &refModel);

                    QPushButton *getBrowseButton();
                    TargetPanelModel &getModel() const;
                    QLabel *getSeparatorLabel();
                    QLineEdit *getTargetFileField();
                    QLabel *getTargetLabel();
                    QLineEdit *getTargetPathField();
                signals:

                };
            }
        }
    }
}
