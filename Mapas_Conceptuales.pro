QT       += core gui quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addsquaredialog.cpp \
    documentsgraphicsscene.cpp \
    main.cpp \
    mainwindow.cpp \
    squaregraphicsobject.cpp \
    squaregraphicsscene.cpp

HEADERS += \
    addsquaredialog.h \
    documentsgraphicsscene.h \
    mainwindow.h \
    squaregraphicsobject.h \
    squaregraphicsscene.h

FORMS += \
    addsquaredialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourcesFile.qrc
