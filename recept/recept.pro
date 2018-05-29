#-------------------------------------------------
#
# Project created by QtCreator 2018-05-18T10:26:00
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = recept
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    database.cpp \
    add_dialog.cpp \
    refresh_dialog.cpp \
    expenddialog.cpp \
    drug.cpp \
    storage.cpp \
    expenditem.cpp \
    optiondialog.cpp \
    inputvalidator.cpp

HEADERS  += mainwindow.h \
    database.h \
    add_dialog.h \
    refresh_dialog.h \
    expenddialog.h \
    drug.h \
    storage.h \
    expenditem.h \
    optiondialog.h \
    inputvalidator.h

FORMS    += mainwindow.ui \
    add_dialog.ui \
    refresh_dialog.ui \
    expenddialog.ui \
    optiondialog.ui
