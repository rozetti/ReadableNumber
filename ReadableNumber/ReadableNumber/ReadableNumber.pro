#-------------------------------------------------
#
# Project created by QtCreator 2015-07-24T13:01:01
#
#-------------------------------------------------
include(../common.pri)

QT       -= gui

TARGET = ReadableNumber
TEMPLATE = lib
CONFIG += staticlib

DEFINES += READABLENUMBER_LIBRARY

SOURCES += \
    ReadableNumber.cpp

HEADERS +=\
    ReadableNumber.h \
    ReadableNumber_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
