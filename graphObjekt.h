#ifndef GRAPHOBJEKT_H
#define GRAPHOBJEKT_H
#include <QPoint>
#include <QPainter>

class GraphObjekt{

public:
    GraphObjekt(QPoint point, QColor color):origin(point),color(color),selected(false){};
    GraphObjekt(const GraphObjekt&) = delete;
    GraphObjekt& operator=(const GraphObjekt&) = delete;
    virtual ~GraphObjekt(){};
    virtual QPoint getOrigin() = 0;
    virtual void setOrigin(QPoint point) = 0;
    virtual void draw(QPainter &painter) = 0;
    virtual void deleteWhenConnected(QPoint selected) = 0;
    virtual void update(QPoint newPoint) = 0;
    virtual bool equalPoints() = 0;
    virtual bool hit(QPoint click) = 0;
    virtual void moveTo(QPoint point) = 0;
    void setSelected(bool b){selected = b;}
    bool getSelected(){return selected;}
    void setColor(QColor color){this->color = color;}
protected:
    QPoint origin;
    QColor color;
    bool selected;
};

#endif // GRAPHOBJEKT_H
