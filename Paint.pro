# http://doc.qt.io/qt-5/qmake-variable-reference.html
CONFIG += console
QT += core widgets gui
DEFINES += QT_WIDGETS_LIB
#LIBS += 
INCLUDEPATH += .

HEADERS += paint.h \
           BBoxDecorator.h \
           graphObjekt.h \
           canvas.h  \
           circle.h \
           freehanddrawing.h \
           line.h \
           polygone.h \
           rectangle.h \
           scene.h \
           triangle.h
SOURCES += paint.cpp \
           canvas.cpp \
           circle.cpp \
           freehanddrawing.cpp \
           line.cpp \
           main.cpp \
           polygone.cpp \
           rectangle.cpp \
           scene.cpp \
           triangle.cpp
