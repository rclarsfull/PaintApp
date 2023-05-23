#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPoint>
#include <QPainter>
#include "GraphObjekt.h"
class Rectangle: public GraphObjekt
{
    QPoint lowerRightCorner;
    bool filled;
public:
    Rectangle(QPoint origen, QPoint lowerRightCorner, QColor color, bool filled);
    ~Rectangle();

    void setPoint(int point);
    QPoint getPoint(int point);
    void setOrigin(QPoint point) override;
    QPoint getOrigin() override;
    void draw(QPainter &painter) override;
    void deleteWhenConnected(QPoint selected) override;
};

#endif // RECTANGLE_H
