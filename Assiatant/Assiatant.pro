#-------------------------------------------------
#
# Project created by QtCreator 2015-08-04T22:49:32
#
#-------------------------------------------------

QT       += core gui
CONFIG += c++11
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Assiatant
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    customedit.cpp \
    regedithelper.cpp \
    customlistwidget.cpp

HEADERS  += mainwindow.h \
    customedit.h \
    regedithelper.h \
    customlistwidget.h


FORMS    += mainwindow.ui
