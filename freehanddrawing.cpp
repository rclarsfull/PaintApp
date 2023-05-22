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
        painter.drawLine(orign, points.front());
        for(int i = 0; i+1 < points.size();i++){
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
