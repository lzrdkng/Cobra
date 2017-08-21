# Created by and for Qt Creator. This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

TARGET = Cobra

DESTDIR = bin

OBJECTS_DIR = obj
MOC_DIR = obj

HEADERS = \
   $$PWD/inc/Application.hpp \
   $$PWD/inc/Color.hpp \
   $$PWD/inc/Object.hpp \
   $$PWD/inc/Pair.hpp \
   $$PWD/inc/Point.hpp \
   $$PWD/inc/Rect.hpp \
   $$PWD/inc/Renderer.hpp \
   $$PWD/inc/Texture.hpp \
   $$PWD/inc/Window.hpp \
   $$PWD/inc/SDL.hpp \
   $$PWD/inc/Object.hpp

SOURCES = \
   $$PWD/src/main.cpp \
   $$PWD/src/Point.cpp \
   $$PWD/src/Rect.cpp \
   $$PWD/src/Renderer.cpp \
   $$PWD/src/Texture.cpp \
   $$PWD/src/Window.cpp \

INCLUDEPATH += $$PWD/inc

QMAKE_CXXFLAGS = -std=gnu++0x

unix:!macx: LIBS += -lSDL2 -lSDL2_image
