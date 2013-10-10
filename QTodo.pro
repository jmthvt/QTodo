#-------------------------------------------------
#
# Project created by QtCreator 2012-12-06T18:35:38
#
#-------------------------------------------------

QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTodo
TEMPLATE = app


SOURCES += main.cpp \
    domparser.cpp \
    note.cpp \
    mainform.cpp

HEADERS  += \
    domparser.h \
    note.h \
    mainform.h

FORMS    += \
    mainform.ui
