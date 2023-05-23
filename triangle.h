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
    void setOrigin(QPoint point);
    QPoint getOrigin();
    void draw(QPainter &painter);
    void deleteWhenConnected(QPoint selected) override;

};

#endif // TRIANGLE_H
