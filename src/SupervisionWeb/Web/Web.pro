# This project demonstrates how to use QtWebAppLib by including the
# sources into this project.

TARGET = Web
TEMPLATE = app
QT = core network
CONFIG += console

HEADERS += \
    src/f_RequeteMapper.h
           

SOURCES += src/main.cpp \
    src/f_RequeteMapper.cpp

OTHER_FILES += etc/* etc/www/*  etc/ssl/*

#---------------------------------------------------------------------------------------
# The following lines include the sources of the QtWebAppLib library
#---------------------------------------------------------------------------------------

include(../Serveur/ServeurHTTP/ServeurHTTP.pri)

