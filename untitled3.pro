#-------------------------------------------------
#
# Project created by QtCreator 2018-12-16T23:53:00
#
#-------------------------------------------------

QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled3
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    decltypewindow.cpp \
    form.cpp \
    frame.cpp \
    senderdialog.cpp \
    receiverdialog.cpp \
    declarantdialog.cpp \
    countrydialog.cpp \
    decllist.cpp \
    calendardialog.cpp \
    declarantdialog.cpp \
    decltypedialog.cpp \
    goodsdialog.cpp \
    excratedialog.cpp \
    transdialog.cpp \
    proddialog.cpp

HEADERS += \
        mainwindow.h \
    decltypewindow.h \
    form.h \
    frame.h \
    senderdialog.h \
    receiverdialog.h \
    declarantdialog.h \
    countrydialog.h \
    decllist.h \
    calendardialog.h \
    declarantdialog.h \
    decltypedialog.h \
    goodsdialog.h \
    excratedialog.h \
    transdialog.h \
    proddialog.h

FORMS += \
        mainwindow.ui \
    decltypewindow.ui \
    form.ui \
    frame.ui \
    senderdialog.ui \
    receiverdialog.ui \
    declarantdialog.ui \
    countrydialog.ui \
    decllist.ui \
    calendardialog.ui \
    declarantdialog.ui \
    decltypedialog.ui \
    goodsdialog.ui \
    excratedialog.ui \
    transdialog.ui \
    proddialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
