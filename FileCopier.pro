QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FileCopierApp.cpp \
    FileCopierButtonPanel.cpp \
    FileCopierController.cpp \
    FileCopierMainPanel.cpp \
    Observer.cpp \
    ProcessButtonPanel.cpp \
    ProcessFilenamePanel.cpp \
    ProcessModel.cpp \
    ProcessPanel.cpp \
    ProcessStatusPanel.cpp \
    SetupButtonPanel.cpp \
    SetupModel.cpp \
    SetupPanel.cpp \
    SourcePanel.cpp \
    SourcePanelModel.cpp \
    SourcePanelObserver.cpp \
    TargetPanel.cpp \
    TargetPanelModel.cpp \
    main.cpp \
    FileCopierMainWindow.cpp

HEADERS += \
    FileCopierApp.h \
    FileCopierButtonPanel.h \
    FileCopierController.h \
    FileCopierMainPanel.h \
    FileCopierMainWindow.h \
    Observer.h \
    ProcessButtonPanel.h \
    ProcessFilenamePanel.h \
    ProcessModel.h \
    ProcessPanel.h \
    ProcessStatusPanel.h \
    SetupButtonPanel.h \
    SetupModel.h \
    SetupPanel.h \
    SourcePanel.h \
    SourcePanelModel.h \
    SourcePanelObserver.h \
    TargetPanel.h \
    TargetPanelModel.h

TRANSLATIONS += \
    FileCopier_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
