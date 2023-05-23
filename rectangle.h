#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPoint>
#include <QPainter>
#include "GraphObjekt.h"
class Rectangle: public GraphObjekt
{
    QPoint qpoints[3];
public:
    Rectangle(QPoint origen, QColor color);
    ~Rectangle();

    void setPoint(int point);
    QPoint getPoint(int point);
    void setOrigin(QPoint point);
    QPoint getOrigin();
    void draw(QPainter &painter);
    void deleteWhenConnected(QPoint selected) override;


};

#endif // RECTANGLE_H
