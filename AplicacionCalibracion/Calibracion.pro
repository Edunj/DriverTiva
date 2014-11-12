#-------------------------------------------------
#
# Project created by QtCreator 2014-09-08T13:35:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calibracion
TEMPLATE = app


SOURCES += main.cpp\
        calibracion.cpp \
    protocol.c \
    crc.c

HEADERS  += calibracion.h \
    protocol.h \
    crc.h

FORMS    += calibracion.ui

CONFIG   +=qwt # Añadir para usar Qwidgets

LIBS += -lqwtd -lQtSerialPortd -lanalogwidgetsd # Añadido Necesario para encontrar implementación de librerias!!
