#include <QBrush>
#include "circle.h"


Circle::Circle(QPoint origen, QPoint outerPoint, QColor color, bool filled):GraphObjekt(origen,color), outerPoint(outerPoint), filled(filled)
{

}

Circle::~Circle()
{

}

void Circle::setOrigin(QPoint point)
{

}

QPoint Circle::getOrigin()
{

}

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
}

void Circle::deleteWhenConnected(QPoint selected)
{

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
