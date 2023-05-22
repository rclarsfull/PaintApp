#include "circle.h"

Circle::Circle(QPoint origen, QPoint outerPoint, QColor color):GraphObjekt(origen,color), outerPoint(outerPoint)
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
    painter.setPen(QPen(color,2, Qt::SolidLine));
    int deltaX = orign.x() - outerPoint.x();
    int deltaY = orign.y() - outerPoint.y();
    int distance =std::sqrt((deltaX+deltaX)+(deltaY*deltaY));
    painter.drawEllipse(orign,distance,distance);
}
