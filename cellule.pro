#-------------------------------------------------
#
# Project created by QtCreator 2013-08-02T17:11:24
#
#-------------------------------------------------

QT       += core gui webkit opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cellule
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

QMAKE_CXXFLAGS += -std=gnu++0x -o3
QMAKE_CFLAGS += -o3
