#-------------------------------------------------
#
# Project created by QtCreator 2019-06-01T17:10:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GoldenAge
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        startwindow.cpp \
    farmwindow.cpp \
    groundwidget.cpp \
    groundwindow.cpp \
    flowershopwindow.cpp \
    birdwindow.cpp \
    alldata.cpp \
    farmdata.cpp \
    birddata.cpp \
    npcdata.cpp \
    fishingwindow.cpp \
    housewindow.cpp

HEADERS += \
        startwindow.h \
    farmwindow.h \
    groundwidget.h \
    groundwindow.h \
    flowershopwindow.h \
    birdwindow.h \
    alldata.h \
    farmdata.h \
    birddata.h \
    npcdata.h \
    fishingwindow.h \
    housewindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc

DISTFILES +=
