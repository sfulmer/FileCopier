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
    ExitWhenDoneObserver.cpp \
    FileCopierApp.cpp \
    FileCopierButtonPanel.cpp \
    FileCopierController.cpp \
    FileCopierMainPanel.cpp \
    Observer.cpp \
    ProcessButtonPanel.cpp \
    ProcessCurrentFileObserver.cpp \
    ProcessFilenamePanel.cpp \
    ProcessModel.cpp \
    ProcessPanel.cpp \
    ProcessStatusObserver.cpp \
    ProcessStatusPanel.cpp \
    ProgressObserver.cpp \
    Properties.cpp \
    Property.cpp \
    PropertyFileIO.cpp \
    ResumeFromLastPositionObserver.cpp \
    SetupButtonPanel.cpp \
    SetupModel.cpp \
    SetupPanel.cpp \
    SourcePanel.cpp \
    SourcePanelModel.cpp \
    SourcePanelObserver.cpp \
    StartButtonObserver.cpp \
    StatusDoneObserver.cpp \
    StatusMovingPausedStalledObserver.cpp \
    TargetPanel.cpp \
    TargetPanelModel.cpp \
    TargetPanelObserver.cpp \
    main.cpp \
    FileCopierMainWindow.cpp

HEADERS += \
    ExitWhenDoneObserver.h \
    FileCopierApp.h \
    FileCopierButtonPanel.h \
    FileCopierController.h \
    FileCopierMainPanel.h \
    FileCopierMainWindow.h \
    Observer.h \
    ProcessButtonPanel.h \
    ProcessCurrentFileObserver.h \
    ProcessFilenamePanel.h \
    ProcessModel.h \
    ProcessPanel.h \
    ProcessStatusObserver.h \
    ProcessStatusPanel.h \
    ProgressObserver.h \
    Properties.h \
    Property.h \
    PropertyFileIO.h \
    ResumeFromLastPositionObserver.h \
    SetupButtonPanel.h \
    SetupModel.h \
    SetupPanel.h \
    SourcePanel.h \
    SourcePanelModel.h \
    SourcePanelObserver.h \
    StartButtonObserver.h \
    StatusDoneObserver.h \
    StatusMovingPausedStalledObserver.h \
    TargetPanel.h \
    TargetPanelModel.h \
    TargetPanelObserver.h

TRANSLATIONS += \
    FileCopier_en_US.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Config.properties
