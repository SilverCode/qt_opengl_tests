#-------------------------------------------------
#
# Project created by QtCreator 2016-03-12T13:13:00
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Butter
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    glwindow.cpp \
    abstractglscene.cpp \
    sceneglwindow.cpp

HEADERS  += widget.h \
    glwindow.h \
    abstractglscene.h \
    sceneglwindow.h

FORMS    += widget.ui
