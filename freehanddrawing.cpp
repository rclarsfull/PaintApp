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
