#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T23:17:10
#
#-------------------------------------------------

QT       += sql

QT       -= gui

TARGET = libVeqtor
TEMPLATE = lib
CONFIG += staticlib

SOURCES += veqtor.cpp

HEADERS += veqtor.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
