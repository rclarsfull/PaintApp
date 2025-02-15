#ifndef CIRCLE_H
#define CIRCLE_H

#include "graphObjekt.h"


class Circle: public GraphObjekt
{
private:
    QPoint outerPoint;
    //bool filled;
public:
    Circle(QPoint origen, QPoint outerPoint, QColor color, bool filled);
    Circle(const Circle&) = delete;
    Circle& operator=(const Circle&) = delete;
    ~Circle() override;
    void draw(QPainter &painter) override;
    void update(QPoint newPoint) override;
    bool isNoSizeObjekt() override;
    bool hit(QPoint click) override;
    void moveTo(QPoint point) override;
    GraphObjekt* copy() override;
    void calcBBox(QPoint &min, QPoint &max) override;
};

#endif // CIRCLE_H
