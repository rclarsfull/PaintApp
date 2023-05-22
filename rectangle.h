#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QPoint>
#include "GraphObjekt.h"
class Rectangle: public GraphObjekt
{
    QPoint qpoints[3];
public:
    Rectangle();


    void setPoint(int point);
    QPoint getPoint(int point);


};

#endif // RECTANGLE_H
