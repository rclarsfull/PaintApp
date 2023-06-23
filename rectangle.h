#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPoint>
#include <QPainter>
#include "graphObjekt.h"
class Rectangle: public GraphObjekt
{
    QPoint lowerRightCorner;
    //bool filled;
public:
    Rectangle(QPoint origen, QPoint lowerRightCorner, QColor color, bool filled);
    Rectangle(const Rectangle&) = delete;
    Rectangle& operator=(const Rectangle&) = delete;
    ~Rectangle();
    void draw(QPainter &painter) override;
    void update(QPoint newPoint) override;
    bool equalPoints() override;
    bool hit(QPoint click) override;
    void moveTo(QPoint point) override;
    GraphObjekt* copy() override;
};

#endif // RECTANGLE_H
