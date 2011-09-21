#-------------------------------------------------
#
# Project created by QtCreator 2011-03-28T09:24:00
#
#-------------------------------------------------

QT       += core gui

TARGET = Bio_Interface
TEMPLATE = app

RC_FILE = ressource.rc

#CONFIG  += CONSOLE


SOURCES += main.cpp\
        mainwindow.cpp \
    addspeciesdialog.cpp \
    species.cpp \
    manager.cpp \
    synth.cpp \
    reaction.cpp \
    inh.cpp \
    complex.cpp \
    inhdialog.cpp \
    complexdialog.cpp \
    synthdialog.cpp \
    system.cpp \
    systemdialog.cpp

HEADERS  += mainwindow.h \
    addspeciesdialog.h \
    species.h \
    manager.h \
    synth.h \
    reaction.h \
    inh.h \
    complex.h \
    inhdialog.h \
    bio_cst.h \
    complexdialog.h \
    synthdialog.h \
    system.h \
    systemdialog.h

FORMS    += mainwindow.ui \
    addspeciesdialog.ui \
    inhdialog.ui \
    complexdialog.ui \
    synthdialog.ui \
    systemdialog.ui

OTHER_FILES += \
    ressource.rc
