######################################################################
# Automatically generated by qmake (2.01a) mer. 18. juin 11:49:49 2008
######################################################################

TEMPLATE = app
QT += webkit network xml
TARGET = Navigator
DEPENDPATH += .
INCLUDEPATH += .

CONFIG += x86

ICON = icone.icns

# Input
HEADERS += FenPrincipale.h \
    prefdialog.h \
    historique.h \
    mytoolbar.h \
    bookmarksdialog.h \
    rsswidget.h \
    apropos.h \
    CookieJar.h \
    helpbrowser.h
SOURCES += FenPrincipale.cpp main.cpp \
    prefdialog.cpp \
    historique.cpp \
    mytoolbar.cpp \
    bookmarksdialog.cpp \
    rsswidget.cpp \
    apropos.cpp \
    CookieJar.cpp \
    helpbrowser.cpp

RESOURCES += \
    rsrc.qrc

FORMS += \
    prefdialog.ui \
    historique.ui \
    bookmarksdialog.ui
