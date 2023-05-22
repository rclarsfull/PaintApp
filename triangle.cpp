#include "triangle.h"

Triangle::Triangle(QPoint origen, QColor color):GraphObjekt(origen, color)
{

}

Triangle::~Triangle()
{

}

void Triangle::setPoint(QPoint qPoint,int point)
{
    if(point < 0 || point > 4)
        return;
    if(point == 3)
        orign = qPoint;
    else
        qPoints[point] = qPoint;
}

QPoint Triangle::getPoint(int point)
{

}

void Triangle::setOrigin(QPoint point)
{

}

QPoint Triangle::getOrigin()
{

}

void Triangle::draw(QPainter &painter)
{

}
