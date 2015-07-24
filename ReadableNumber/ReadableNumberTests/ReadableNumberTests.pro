#-------------------------------------------------
#
# Project created by QtCreator 2015-07-24T12:51:54
#
#-------------------------------------------------
include(../common.pri)

QT       += testlib

QT       -= gui

TARGET = ReadableNumberTests
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += ReadableNumberTests.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ReadableNumber/release/ -lReadableNumber
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ReadableNumber/debug/ -lReadableNumber
else:unix: LIBS += -L$$OUT_PWD/../ReadableNumber/ -lReadableNumber

INCLUDEPATH += $$PWD/../ReadableNumber
DEPENDPATH += $$PWD/../ReadableNumber

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ReadableNumber/release/libReadableNumber.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ReadableNumber/debug/libReadableNumber.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ReadableNumber/release/ReadableNumber.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ReadableNumber/debug/ReadableNumber.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../ReadableNumber/libReadableNumber.a
