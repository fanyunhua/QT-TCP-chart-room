#-------------------------------------------------
#
# Project created by QtCreator 2019-07-04T12:43:27
#
#-------------------------------------------------

QT       += core

QT       -= gui
QT       += sql
QT       += network

TARGET = QT_TCP_Server
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    tcpconnect.cpp \
    databasehelper.cpp \
    dataparser.cpp

HEADERS += \
    tcpconnect.h \
    databasehelper.h \
    dataparser.h
