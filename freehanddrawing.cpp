#include <QDebug>
#include "freehanddrawing.h"

FreeHandDrawing::FreeHandDrawing(QPoint origen, QColor color):GraphObjekt(origen,color, false){}

FreeHandDrawing::FreeHandDrawing(QPoint origin, QColor color, std::vector<QPoint> points): GraphObjekt(origin, color, false), points(points){}

FreeHandDrawing::~FreeHandDrawing(){}

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

void FreeHandDrawing::update(QPoint newPoint)
{
    if(points.size()>1){
        QPoint vec = points.back() - newPoint;
        if((vec.x()*vec.x() + vec.y()*vec.y() > 25))
            points.push_back(newPoint);
    }else
        points.push_back(newPoint);
}

bool FreeHandDrawing::isNoSizeObjekt()
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

GraphObjekt *FreeHandDrawing::copy()
{
    return new FreeHandDrawing(origin, color, points);
}

void FreeHandDrawing::calcBBox(QPoint &min, QPoint &max)
{
    int xmin,xmax, ymin, ymax;
    xmin = xmax = origin.x();
    ymin = ymax = origin.y();
    for (unsigned int i = 0; i < points.size(); ++i) {
        QPoint p = points.at(i);
        if(p.x() < xmin)
            xmin = p.x();
        if(p.x() > xmax)
            xmax = p.x();
        if(p.y() < ymin)
            ymin = p.y();
        if(p.y() > ymax)
            ymax = p.y();
    }
    min = QPoint(xmin, ymin);
    max = QPoint(xmax, ymax);
}
