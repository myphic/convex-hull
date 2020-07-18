#-------------------------------------------------
#
# Project created by QtCreator 2016-12-25T16:00:50
#
#-------------------------------------------------

QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project
TEMPLATE = app


SOURCES += main.cpp\
    widget.cpp \
    agent.cpp \
    monster.cpp \
    player.cpp \
    room.cpp \
    form.cpp \
    object.cpp \
    items.cpp \
    fixeditem.cpp \
    game.cpp \
    treasure.cpp

HEADERS  += widget.h \
    agent.h \
    monster.h \
    player.h \
    room.h \
    form.h \
    object.h \
    items.h \
    fixeditem.h \
    game.h \
    treasure.h

FORMS    += widget.ui \
    form.ui

DISTFILES += \
    project.pro.user \
    characterselect.mp3 \
    thumb-1920-305733.jpg \
    dracula.png \
    palace.png

RESOURCES +=
