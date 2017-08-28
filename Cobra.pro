# Created by and for Qt Creator. This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

TEMPLATE = lib
DESTDIR = lib

OBJECTS_DIR = obj
MOC_DIR = obj

HEADERS = inc/*.hpp
SOURCES = src/*.cpp

INCLUDEPATH += inc

QMAKE_CXXFLAGS = -std=gnu++11

QT     -= gui core
LIBS   -= -lQtGui -lQtCore

LIBS += -lSDL2 -lSDL2_image

DISTFILES += \
    README.md \
    LICENSE.txt
