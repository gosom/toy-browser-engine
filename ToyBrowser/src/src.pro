include(../defaults.pri)

CONFIG   += console
CONFIG   -= app_bundle
CONFIG   -= qt

TEMPLATE = lib

TARGET = toy

SOURCES += \
    nodes/node.cpp \
    nodes/elementnode.cpp \
    nodes/textnode.cpp

HEADERS += \
    nodes/node.h \
    nodes/elementnode.h \
    nodes/textnode.h


