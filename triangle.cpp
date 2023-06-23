#include "triangle.h"

Triangle::Triangle(QPoint origen, QColor color):GraphObjekt(origen, color, false){}

Triangle::~Triangle(){}

void Triangle::draw(QPainter &painter)
{

}

bool Triangle::equalPoints()
{
 return false;
}

void Triangle::moveTo(QPoint newPoint)
{

}
