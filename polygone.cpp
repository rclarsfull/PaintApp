#include "polygone.h"

Polygone::Polygone(QPoint origen, QColor color):GraphObjekt(origen,color,false), points(), valid(false){}

Polygone::~Polygone(){}

void Polygone::draw(QPainter &painter)
{
    if(!valid){
        painter.setPen(QPen(Qt::red,2,Qt::SolidLine));
        painter.setBrush(QBrush(Qt::SolidPattern));
        painter.drawEllipse(origin,5,5);
        for(unsigned int i = 0; i < points.size();i++){
            painter.drawEllipse(points[i],5,5);
        }
    }

    painter.setBrush(QBrush(Qt::NoBrush));
    if(filled)
        painter.setBrush(QBrush(color, Qt::SolidPattern));
    if(points.size() > 0){
        painter.setPen(QPen(color,2,Qt::SolidLine));
        painter.drawLine(origin, points.front());
        for(unsigned int i = 1; i < points.size();i++){
            painter.drawLine(points[i-1],points[i]);
        }
        if(valid)
            painter.drawLine(points.back(), origin);
        painter.setBrush(QBrush(color, Qt::NoBrush));
    }
}

void Polygone::update(QPoint newPoint)
{

}

bool Polygone::equalPoints()
{
    return false;
}

bool Polygone::hit(QPoint click)
{
    return false;
}

void Polygone::calcBBox(QPoint &min, QPoint &max)
{

}

GraphObjekt *Polygone::copy()
{
    return new Polygone(origin, color); // need other construcktor
}

void Polygone::moveTo(QPoint point)
{

}

void calcBBox(QPoint &min, QPoint &max){

}

void Polygone::addPoint(QPoint point){
    QPoint vec = origin - point;
    if((vec.x()*vec.x() + vec.y()*vec.y()) > 25){
        points.push_back(point);
   }else
    valid = true;
}

bool Polygone::isValid(){
    return valid;
}
