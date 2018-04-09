QT += quick charts
CONFIG += c++11 qmlcompiler optimize_full

DEFINES += QT_DEPRECATED_WARNINGS

#QMAKE_CXXFLAGS_RELEASE += -O2

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    sistemaimunologico.cpp \
    celulas/celula.cpp \
    celulas/macrofago.cpp \
    celulas/patogeno.cpp \
    celulas/neutrofilo.cpp \
    quimica/camadaquimica.cpp \
    quimica/compostoquimico.cpp \
    estatisticas/virus.cpp \
    celulas/linfocito.cpp \
    celulas/celulab.cpp \
    celulas/anticorpo.cpp \
    celulas/dendridica.cpp \
    celulas/comum.cpp

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    sistemaimunologico.h \
    celulas/celula.h \
    celulas/macrofago.h \
    celulas/patogeno.h \
    celulas/neutrofilo.h \
    quimica/camadaquimica.h \
    quimica/compostoquimico.h \
    estatisticas/virus.h \
    celulas/linfocito.h \
    celulas/celulab.h \
    celulas/anticorpo.h \
    celulas/dendridica.h \
    celulas/comum.h


SUBDIRS += \
    SIA_QT.pro

RESOURCES += \
    qml.qrc

RC_ICONS = icone.ico

DISTFILES += \
    qtquickcontrols2.conf
