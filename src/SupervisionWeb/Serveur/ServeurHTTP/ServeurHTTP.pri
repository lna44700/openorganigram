INCLUDEPATH += $$PWD
DEPENDPATH += $$PWD

QT += network

# Enable very detailed debug messages when compiling the debug version
CONFIG(debug, debug|release) {
    DEFINES += SUPERVERBOSE
}

HEADERS += \
    $$PWD/PoolGestionnaireConnexionHTTP.h \
    $$PWD/ControleurFichierStatique.h \
    $$PWD/EcouteHTTP.h \
    $$PWD/GestionnaireConnexionHTTP.h \
    $$PWD/GestionnaireRequeteHTTP.h \
    $$PWD/GlobalHTTP.h \
    $$PWD/ReponseHTTP.h \
    $$PWD/RequeteHTTP.h

SOURCES += \
    $$PWD/ControleurFichierStatique.cpp \
    $$PWD/EcouteHTTP.cpp \
    $$PWD/GestionnaireConnexionHTTP.cpp \
    $$PWD/GestionnaireRequeteHTTP.cpp \
    $$PWD/GlobalHTTP.cpp \
    $$PWD/RequeteHTTP.cpp \
    $$PWD/ReponseHTTP.cpp \
    $$PWD/PoolGestionnaireConnexionHTTP.cpp
