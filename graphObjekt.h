#ifndef GRAPHOBJEKT_H
#define GRAPHOBJEKT_H
#include <QPoint>
#include <QPainter>

class GraphObjekt{
    GraphObjekt();
    ~GraphObjekt();
public:
    virtual QPoint getOrigin() = 0;
    virtual QPoint setOrigin() = 0;
    virtual void draw(QPainter painter) = 0;
protected:
    QPoint orign;

};

#endif // GRAPHOBJEKT_H
