QT          += opengl widgets

HEADERS     = glwidget.h \
              helper.h \
              widget.h \
              window.h \
    maze.h
SOURCES     = glwidget.cpp \
              helper.cpp \
              main.cpp \
              widget.cpp \
              window.cpp \
    maze.cpp


simulator: warning(This example might not fully work on Simulator platform)


#======== Translation ===============
TRANSLATIONS    = app_en.ts
CODECFORTR      = UTF-8

CONFIG (debug, debug|release) {
    CONFIG       += console
}
