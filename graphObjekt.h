#ifndef GRAPHOBJEKT_H
#define GRAPHOBJEKT_H
#include <QPoint>
#include <QPainter>

class GraphObjekt{

public:
    GraphObjekt(QPoint point, QColor color):origin(point),color(color){};
    GraphObjekt(const GraphObjekt &graphobject) = delete;
    virtual ~GraphObjekt(){};
    virtual QPoint getOrigin() = 0;
    virtual void setOrigin(QPoint point) = 0;
    virtual void draw(QPainter &painter) = 0;
    virtual void deleteWhenConnected(QPoint selected) = 0;
    virtual void update(QPoint newPoint) = 0;
    virtual bool equalPoints() = 0;
protected:
    QPoint origin;
    QColor color;

};

#endif // GRAPHOBJEKT_H
