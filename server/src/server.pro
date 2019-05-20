#-------------------------------------------------
#
# Project created by QtCreator 2019-05-14T18:08:13
#
#-------------------------------------------------

QT       += core gui
QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = server
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
        serverwidget.cpp \
    resolver.cpp

HEADERS += \
        serverwidget.h \
    resolver.h

FORMS += \
        serverwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix:!macx|win32: LIBS += -L$$PWD/../../libs/libzplay-2.02-sdk/C++/ -lzplay

INCLUDEPATH += $$PWD/../../libs/libzplay-2.02-sdk/C++
DEPENDPATH += $$PWD/../../libs/libzplay-2.02-sdk/C++

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/../../libs/libzplay-2.02-sdk/C++/zplay.lib
else:unix:!macx|win32-g++: PRE_TARGETDEPS += $$PWD/../../libs/libzplay-2.02-sdk/C++/libzplay.a
