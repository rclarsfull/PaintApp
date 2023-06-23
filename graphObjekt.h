#ifndef GRAPHOBJEKT_H
#define GRAPHOBJEKT_H
#include <QPoint>
#include <QPainter>

class GraphObjekt{

public:
    GraphObjekt(QPoint point, QColor color, bool filled):origin(point), color(color), selected(false),filled(filled){};
    GraphObjekt(const GraphObjekt& g) = delete;
    GraphObjekt& operator=(const GraphObjekt&) = delete;
    virtual ~GraphObjekt(){};
    virtual void draw(QPainter &painter) = 0;
    virtual void update(QPoint newPoint) = 0;
    virtual bool equalPoints() = 0;
    virtual bool hit(QPoint click) = 0;
    virtual void moveTo(QPoint point) = 0;
    virtual GraphObjekt* copy() = 0;
    virtual void calcBBox(QPoint &min, QPoint &max) = 0;
    virtual bool isValid() {return true;};
    void setSelected(bool b){selected = b;}
    bool getSelected(){return selected;}
    void setColor(QColor color){this->color = color;}
    bool getFilled(){return filled;}
    void setFilled(bool filled){this->filled = filled;}
protected:
    QPoint origin;
    QColor color;
    bool selected;
    bool filled;
};

#endif // GRAPHOBJEKT_H
