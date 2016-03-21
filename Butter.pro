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
    scene_box.cpp \
    scene_shader.cpp

HEADERS  += widget.h \
    glwindow.h \
    abstractglscene.h \
    sceneglwindow.h \
    scene_box.h \
    scene_shader.h

FORMS    += widget.ui

RESOURCES += \
    textures.qrc

DISTFILES += \
    phong.vert \
    phong.frag
