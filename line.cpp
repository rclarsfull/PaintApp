#include <math.h>
#include <QDebug>
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
    painter.drawLine(origin,endPoint);
    if(selected){
        painter.setPen(QPen(QColor("red"),2, Qt::SolidLine));
        painter.drawEllipse(origin, 5, 5);
        painter.drawEllipse(endPoint, 5, 5);
    }
}

void Line::deleteWhenConnected(QPoint selected)
{

}

void Line::update(QPoint newPoint)
{
    endPoint = newPoint;
}

bool Line::equalPoints()
{
    if(origin.x() == endPoint.x() && origin.y() == endPoint.y())
        return true;
    return false;
}

bool Line::hit(QPoint click)
{//t0 = (click - Start) ⋅ line / |line|2  ->  dann intersecPoint = start + t0 * lineVec  ->  dann betrag click-inter
    QPoint startToCLick = click - origin;
    QPoint lineVec = endPoint - origin;
    float t = (float)(startToCLick.x() * lineVec.x() + startToCLick.y() * lineVec.y()) / (float)(lineVec.x() * lineVec.x() + lineVec.y() * lineVec.y());
    QPoint intersect = origin + t*lineVec;
    QPoint v = intersect - click;
    float distance = sqrt(v.x() * v.x() + v.y() * v.y());
    //qDebug() << distance;
    return (distance < 10) && (0 <= t && t <= 1);
}

void Line::moveTo(QPoint point)
{
    origin = origin + point;
    endPoint = endPoint + point;
}
