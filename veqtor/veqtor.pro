QT += core
QT += sql
QT -= gui

CONFIG += c++11

TARGET = veqtor
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    veqtorcommand.cpp

HEADERS += \
    veqtorcommand.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../libVeqtor/release/ -llibVeqtor
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../libVeqtor/debug/ -llibVeqtor
else:unix: LIBS += -L$$OUT_PWD/../libVeqtor/ -llibVeqtor

INCLUDEPATH += $$PWD/../libVeqtor
DEPENDPATH += $$PWD/../libVeqtor

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libVeqtor/release/liblibVeqtor.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libVeqtor/debug/liblibVeqtor.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libVeqtor/release/libVeqtor.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../libVeqtor/debug/libVeqtor.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../libVeqtor/liblibVeqtor.a

