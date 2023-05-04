#-------------------------------------------------
#
# Project created by QtCreator 2021-01-19T14:09:15
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Acquisition_sismique_lilian
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
QMAKE_CXXFLAGS   = -DRASPBERRY_PI -DBCM2835_NO_DELAY_COMPATIBILITY
LIBS          += -lbcm2835 -lwiringPi
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        widget.cpp \
    ads1115.cpp \
    sgbd.cpp \
    serveurtcp.cpp \
    clienttcp.cpp

HEADERS  += widget.h \
    ads1115.h \
    ads1115api.h \
    sgbd.h \
    serveurtcp.h \
    clienttcp.h

FORMS    += widget.ui
