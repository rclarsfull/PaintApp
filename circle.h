#ifndef CIRCLE_H
#define CIRCLE_H

#include "graphObjekt.h"


class Circle: public GraphObjekt
{
private:
    QPoint outerPoint;
public:
    Circle(QPoint origen, QPoint outerPoint, QColor color);
    ~Circle() override;
    void setOrigin(QPoint point) override;
    QPoint getOrigin() override;
    void draw(QPainter &painter) override;
};

#endif // CIRCLE_H
