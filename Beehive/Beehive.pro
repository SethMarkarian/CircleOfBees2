
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WeatherGUI
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

#TEMPLATE = app
CONFIG += console c++11
#CONFIG -= app_bundle
#CONFIG -= qt

SOURCES += \
        main.cpp \
    bee.cpp \
    queen.cpp \
    beehive.cpp \
    drone.cpp \
    brood.cpp \
    worker.cpp \
    forager.cpp \
    juvinile.cpp \
    nurse.cpp \
    board.cpp \
    ../WeatherGUI/mainwindow.cpp

HEADERS += \
    bee.h \
    queen.h \
    beehive.h \
    drone.h \
    brood.h \
    worker.h \
    forager.h \
    juvinile.h \
    nurse.h \
    board.h \
../WeatherGUI/mainwindow.h

FORMS += \
        ../WeatherGUI/mainwindow.ui

qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
