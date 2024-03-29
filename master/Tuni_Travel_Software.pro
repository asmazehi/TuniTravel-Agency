QT       += core gui sql network multimedia multimediawidgets charts printsupport widgets axcontainer serialport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adresseemail.cpp \
    arduino.cpp \
    client.cpp \
    dialog.cpp \
    employee.cpp \
    fourniture.cpp \
    gs_client.cpp \
    gs_employee.cpp \
    gs_offre.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    offre.cpp \
    todolist_e.cpp

HEADERS += \
    adresseemail.h \
    arduino.h \
    client.h \
    dialog.h \
    employee.h \
    fourniture.h \
    gs_client.h \
    gs_employee.h \
    gs_offre.h \
    login.h \
    mainwindow.h \
    offre.h \
    todolist_e.h

FORMS += \
    dialog.ui \
    gs_client.ui \
    gs_employee.ui \
    gs_offre.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
