#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPoint>
#include "GraphObjekt.h"

class Triangle: public GraphObjekt
{
    QPoint qPoints[2];
public:
    Triangle(QPoint origen, QColor color);
    ~Triangle();

    void setPoint(QPoint qPoint,int point);
    QPoint getPoint(int point);
    void setOrigin(QPoint point) override;
    QPoint getOrigin() override;
    void draw(QPainter &painter) override;
    void deleteWhenConnected(QPoint selected) override;
    bool equalPoints() override;
    //void moveTo(QPoint newPoint) override;
};

#endif // TRIANGLE_H
