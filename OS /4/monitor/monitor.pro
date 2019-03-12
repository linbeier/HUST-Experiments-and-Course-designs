#-------------------------------------------------
#
# Project created by QtCreator 2019-02-20T09:26:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = monitor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ../build-monitor-Desktop_Qt_5_5_1_GCC_32bit-Debug/qcustomplot/qcustomplot.cpp

HEADERS  += mainwindow.h \
    ../build-monitor-Desktop_Qt_5_5_1_GCC_32bit-Debug/qcustomplot/qcustomplot.h

FORMS    += mainwindow.ui
