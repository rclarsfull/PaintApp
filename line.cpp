#include "line.h"

Line::Line(QPoint a_beginPoint,QPoint a_endPoint, QColor color):GraphObjekt(a_beginPoint, color), endPoint(a_endPoint)
{

}

Line::~Line()
{

}

QPoint Line::getEndPoint()
{

}

void Line::setEndPoint()
{

}

void Line::setOrigin(QPoint point)
{

}

QPoint Line::getOrigin()
{

}

void Line::draw(QPainter &painter)
{
    painter.setPen(QPen(color,2, Qt::SolidLine));
    painter.drawLine(orign,endPoint);
}

void Line::deleteWhenConnected(QPoint selected)
{

}
