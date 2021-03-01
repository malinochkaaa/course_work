QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    create_column.cpp \
    database.cpp \
    db_thirddialog.cpp \
    fk_create.cpp \
    main.cpp \
    mainwindow.cpp \
    secdialog.cpp

HEADERS += \
    create_column.h \
    database.h \
    db_thirddialog.h \
    fk_create.h \
    mainwindow.h \
    secdialog.h

FORMS += \
    create_column.ui \
    db_thirddialog.ui \
    fk_create.ui \
    mainwindow.ui \
    secdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
