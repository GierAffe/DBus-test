#-------------------------------------------------
#
# Project created by QtCreator 2014-08-28T23:02:02
#
#-------------------------------------------------

QT       += core gui
QT       += dbus

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DBus-test
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    maindbus.cpp

HEADERS  += mainwindow.h \
    maindbus.h

FORMS    += mainwindow.ui
