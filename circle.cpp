#include <QBrush>
#include <QDebug>
#include <math.h>
#include "circle.h"


Circle::Circle(QPoint origen, QPoint outerPoint, QColor color, bool filled):GraphObjekt(origen,color, filled), outerPoint(outerPoint){}

Circle::~Circle(){}

void Circle::draw(QPainter &painter)
{
    if(filled)
        painter.setBrush(QBrush(color, Qt::SolidPattern));

    painter.setPen(QPen(color,2, Qt::SolidLine));
    int deltaX = origin.x() - outerPoint.x();
    int deltaY = origin.y() - outerPoint.y();
    int distance = std::sqrt((deltaX*deltaX)+(deltaY*deltaY));
    painter.drawEllipse(origin,distance,distance);
    painter.setBrush(QBrush(color, Qt::NoBrush));
    if(selected){
        painter.setPen(QPen(QColor("red"),5, Qt::DashLine));
        painter.drawEllipse(origin, distance, distance);
    }
}

void Circle::update(QPoint newPoint)
{
    outerPoint = newPoint;
}

bool Circle::equalPoints()
{
    if(origin.x() == outerPoint.x() && origin.y() == outerPoint.y())
        return true;
    return false;
}

bool Circle::hit(QPoint click)
{
    QPoint circleVec = outerPoint - origin;
    QPoint clickVec = click - origin;

    int rad = std::sqrt(circleVec.x()*circleVec.x() + circleVec.y()*circleVec.y());
    int distance = std::sqrt(clickVec.x()*clickVec.x() + clickVec.y()*clickVec.y());

    if(filled){
        return distance <= rad;
    }else{
        return (distance < rad + 10 && distance > rad - 10);
    }
}

void Circle::moveTo(QPoint point)
{
    origin = origin + point;
    outerPoint = outerPoint + point;
}

GraphObjekt *Circle::copy()
{
    return new Circle(origin, outerPoint, color, filled);
}

void Circle::calcBBox(QPoint &min, QPoint &max)
{
    QPoint circleVec = outerPoint - origin;
    float rad = std::sqrt(circleVec.x()*circleVec.x() + circleVec.y()*circleVec.y());
    min = QPoint(origin.x()-rad, origin.y()-rad);
    max = QPoint(origin.x()+rad, origin.y()+rad);
}
