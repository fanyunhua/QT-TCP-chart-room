#-------------------------------------------------
#
# Project created by QtCreator 2019-07-01T10:05:25
#
#-------------------------------------------------

QT       += core gui
QT += sql
#very important
QT       += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = group_chart
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    databasehepler.cpp \
    updatepassword.cpp \
    tcpconnect.cpp \
    jsonparser.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    databasehepler.h \
    updatepassword.h \
    tcpconnect.h \
    jsonparser.h

FORMS    += mainwindow.ui \
    dialog.ui \
    updatepassword.ui
