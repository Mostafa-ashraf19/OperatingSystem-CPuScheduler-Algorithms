QT       += core gui charts

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
    GraphicalCharts/charts_representation.cpp \
    SchedulerAlgorithms/FCFC.cpp \
    SchedulerAlgorithms/Priorty_Twice.cpp \
    SchedulerAlgorithms/Round_Robin.cpp \
    SchedulerAlgorithms/SJF_Twice.cpp \
    inputdialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    GraphicalCharts/charts_representation.h \
    Macros_Definitions.h \
    SchedulerAlgorithms/FCFS.h \
    SchedulerAlgorithms/FCFS.h \
    SchedulerAlgorithms/Priorty_Twice.h \
    SchedulerAlgorithms/Round_Robin.h \
    SchedulerAlgorithms/SJF_Twice.h \
    inputdialog.h \
    mainwindow.h

FORMS += \
    inputdialog.ui \
    mainwindow.ui

RC_ICONS = Martz90-Circle-Plex.ico

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
