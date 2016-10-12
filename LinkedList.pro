#-------------------------------------------------
#
# Project created by QtCreator 2016-01-11T14:22:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LinkedList
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Node.cpp \
    LinkedList.cpp \
    NodeNumAddEdit.cpp \
    NodeNumDeleteEdit.cpp \
    pictureLabel.cpp

HEADERS  += mainwindow.h \
    Node.h \
    LinkedList.h \
    NodeNumAddEdit.h \
    NodeNumDeleteEdit.h \
    pictureLabel.h

FORMS    += mainwindow.ui

CONFIG += c++11

RESOURCES += \
    pictures.qrc
