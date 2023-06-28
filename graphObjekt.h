#ifndef GRAPHOBJEKT_H
#define GRAPHOBJEKT_H
#include <QPoint>
#include <QPainter>

class GraphObjekt{

public:
    GraphObjekt(QPoint point, QColor color, bool filled):origin(point), color(color), selected(false),filled(filled){};
    GraphObjekt(const GraphObjekt& g): origin(g.origin), color(g.color), selected(false), filled(g.filled){};
    GraphObjekt& operator=(const GraphObjekt&) = delete;
    virtual ~GraphObjekt(){};
    virtual void draw(QPainter &painter) = 0;
    virtual void update(QPoint newPoint) = 0;
    virtual bool hit(QPoint click) = 0;
    virtual void moveTo(QPoint point) = 0;
    virtual GraphObjekt* copy() = 0;
    virtual void calcBBox(QPoint &min, QPoint &max) = 0;
    virtual bool isValid() {return true;}
    virtual bool isNoSizeObjekt() {return false;}
    virtual void setSelected(bool b){selected = b;}
    virtual bool getSelected(){return selected;}
    virtual void setColor(QColor color){this->color = color;}
    virtual bool getFilled(){return filled;}
    virtual void setFilled(bool filled){this->filled = filled;}
protected:
    QPoint origin;
    QColor color;
    bool selected;
    bool filled;
};

#endif // GRAPHOBJEKT_H
