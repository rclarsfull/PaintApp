#include <QDebug>
#include "freehanddrawing.h"

FreeHandDrawing::FreeHandDrawing(QPoint origen, QColor color):GraphObjekt(origen,color)
{

}

FreeHandDrawing::~FreeHandDrawing()
{

}

void FreeHandDrawing::draw(QPainter &painter)
{
    painter.setPen(QPen(color,2, Qt::SolidLine));
    if(points.size() > 0){
        painter.drawLine(origin, points.front());
        for(unsigned int i = 0; i+1 < points.size();i++){
            painter.drawLine(points.at(i),points.at(i+1));
        }
        if(selected){
            painter.setPen(QPen(QColor("red"),2, Qt::SolidLine));
            painter.drawEllipse(origin, 5, 5);
            painter.drawEllipse(*(points.end()-1), 5, 5);
        }
    }
}

void FreeHandDrawing::addPoint(QPoint point)
{
    points.push_back(point);
}

void FreeHandDrawing::setOrigin(QPoint point)
{

}

QPoint FreeHandDrawing::getOrigin()
{

}

void FreeHandDrawing::deleteWhenConnected(QPoint selected)
{

}

void FreeHandDrawing::update(QPoint newPoint)
{

}

bool FreeHandDrawing::equalPoints()
{
    if(points.size() > 2)
        return false;
    return true;
}

bool FreeHandDrawing::hit(QPoint click)
{
    for (unsigned int i = 0; i < points.size(); ++i) {
        QPoint clickVec = click - points.at(i);

        float distance = std::sqrt(clickVec.x()*clickVec.x() + clickVec.y()*clickVec.y());
        if(distance < 10) return true;
    }
    return false;
}

void FreeHandDrawing::moveTo(QPoint point)
{
    origin = origin + point;
    for (unsigned int i = 0; i < points.size(); ++i) {
        points.at(i) = points.at(i) + point;
    }
}
