#include "polygone.h"

Polygone::Polygone(QPoint origen, QColor color):GraphObjekt(origen,color,false){}

Polygone::~Polygone(){}

void Polygone::draw(QPainter &painter)
{

}

void Polygone::update(QPoint newPoint)
{

}

bool Polygone::equalPoints()
{
    return false;
}
