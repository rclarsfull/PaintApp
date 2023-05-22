#ifndef GRAPHOBJEKT_H
#define GRAPHOBJEKT_H
#include <QPoint>
#include <QPainter>

class GraphObjekt{

public:
    GraphObjekt(QPoint point, QColor color):orign(point),color(color){};
    virtual ~GraphObjekt(){};
    virtual QPoint getOrigin() = 0;
    virtual void setOrigin(QPoint point) = 0;
    virtual void draw(QPainter &painter) = 0;
protected:
    QPoint orign;
    QColor color;

};

#endif // GRAPHOBJEKT_H
