#-------------------------------------------------
#
# Project created by QtCreator 2016-10-23T10:40:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab10
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Dictionary.cpp \
    adddialog.cpp

HEADERS  += mainwindow.h \
    Dictionary.h \
    adddialog.h

FORMS    += mainwindow.ui \
    adddialog.ui
