#-------------------------------------------------
#
# Project created by QtCreator 2017-01-05T10:13:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = progettoP2
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


SOURCES += main.cpp \
    logica/prodotto.cpp \
    logica/database.cpp \
    logica/utente.cpp \
    logica/controller_utente.cpp \
    logica/controller_admin.cpp \
    grafica/mainwindow.cpp \
    grafica/pannello_utente.cpp \
    grafica/pannello_admin.cpp \
    grafica/pannello_admin_prod.cpp \
    grafica/pannello_admin_user.cpp

HEADERS  += \
    logica/prodotto.h \
    logica/utente.h \
    logica/database.h \
    logica/controller_utente.h \
    logica/controller_admin.h \
    grafica/mainwindow.h \
    grafica/pannello_admin.h \
    grafica/pannello_utente.h \
    grafica/pannello_admin_prod.h \
    grafica/pannello_admin_user.h

DISTFILES +=
