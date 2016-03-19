#-------------------------------------------------
#
# Project created by QtCreator 2016-03-12T13:13:00
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Butter
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        widget.cpp \
    glwindow.cpp \
    abstractglscene.cpp \
    sceneglwindow.cpp \
    mainscene.cpp

HEADERS  += widget.h \
    glwindow.h \
    abstractglscene.h \
    sceneglwindow.h \
    mainscene.h

FORMS    += widget.ui

RESOURCES += \
    textures.qrc
