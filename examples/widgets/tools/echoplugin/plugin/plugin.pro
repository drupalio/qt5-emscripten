#! [0]
TEMPLATE        = lib
CONFIG         += plugin
INCLUDEPATH    += ../echowindow
HEADERS         = echoplugin.h
SOURCES         = echoplugin.cpp
TARGET          = $$qtLibraryTarget(echoplugin)
DESTDIR         = ../plugins
#! [0]

EXAMPLE_FILES = echoplugin.json

# install
target.path = $$[QT_INSTALL_EXAMPLES]/tools/echoplugin/plugin
INSTALLS += target

QT += widgets
