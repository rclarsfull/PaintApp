#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPoint>
#include <QPainter>
#include "graphObjekt.h"
class Rectangle: public GraphObjekt
{
    QPoint lowerRightCorner;
    bool filled;
public:
    Rectangle(QPoint origen, QPoint lowerRightCorner, QColor color, bool filled);
    Rectangle(const Rectangle&) = delete;
    Rectangle& operator=(const Rectangle&) = delete;
    ~Rectangle();

    void setPoint(int point);
    QPoint getPoint(int point);
    void setOrigin(QPoint point) override;
    QPoint getOrigin() override;
    void draw(QPainter &painter) override;
    void deleteWhenConnected(QPoint selected) override;
    void update(QPoint newPoint) override;
    bool equalPoints() override;
    bool hit(QPoint click) override;
    void moveTo(QPoint point) override;
};

#endif // RECTANGLE_H
