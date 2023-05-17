# http://doc.qt.io/qt-5/qmake-variable-reference.html
CONFIG += console
QT += core widgets gui
DEFINES += QT_WIDGETS_LIB
#LIBS += 
INCLUDEPATH += .

HEADERS += paint.h \
           GraphObjekt.h \
           canvas.h  \
           circle.h \
           freehanddrawing.h \
           line.h \
           triangle.h
SOURCES += paint.cpp \
           canvas.cpp \
           circle.cpp \
           freehanddrawing.cpp \
           line.cpp \
           main.cpp \
           triangle.cpp
