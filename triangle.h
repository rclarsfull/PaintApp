#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPoint>
#include "graphObjekt.h"

class Triangle: public GraphObjekt
{
    QPoint qPoints[2];
public:
    Triangle(QPoint origen, QColor color);
    Triangle(const Triangle&) = delete;
    Triangle& operator=(const Triangle&) = delete;
    ~Triangle();
    void draw(QPainter &painter) override;
    bool equalPoints() override;
    void moveTo(QPoint newPoint) override;
};

#endif // TRIANGLE_H
