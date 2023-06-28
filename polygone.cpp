#include "polygone.h"
#include "qdebug.h"

Polygone::Polygone(QPoint origen, QColor color, bool filled):GraphObjekt(origen,color,filled), valid(false), poligone(){
    poligone << origen;
}

Polygone::Polygone(QPoint origen, QColor color, QPolygon poligone, bool filled):GraphObjekt(origen,color,filled), valid(true), poligone(poligone){}

Polygone::~Polygone(){}

void Polygone::draw(QPainter &painter)
{
    if(!valid){
        painter.setPen(QPen(Qt::red,2,Qt::SolidLine));
        painter.setBrush(QBrush(Qt::SolidPattern));
        painter.drawEllipse(origin,4,4);
//        for(unsigned int i = 0; i < poligone.size();i++){
//            painter.drawEllipse(poligone.point(i),4,4);
//        }
    }
    painter.setPen(QPen(color,2,Qt::SolidLine));
    if(valid && filled){
        painter.setBrush(QBrush(color, Qt::SolidPattern));
    }else{
        painter.setBrush(QBrush(Qt::NoBrush));
    }
    painter.drawPolygon(poligone);
    if(selected){
        painter.setPen(QPen(Qt::red,5,Qt::DashLine));
        painter.drawPolygon(poligone);
    }
}

void Polygone::update(QPoint newPoint)
{
    QPoint vec = origin - newPoint;
    if((vec.x()*vec.x() + vec.y()*vec.y()) > 25){
        poligone << newPoint;
    }else
        valid = true;
}

bool Polygone::hit(QPoint click)
{
    if(!filled){
        for(unsigned int i = 1; i <= poligone.size();i++){
            QPoint startToClick = click - poligone.point((i-1)%poligone.size());
            QPoint lineVec = poligone.point(i%poligone.size()) - poligone.point((i-1)%poligone.size());
            float t = (float)(startToClick.x() * lineVec.x() + startToClick.y() * lineVec.y()) / (float)(lineVec.x() * lineVec.x() + lineVec.y() * lineVec.y());
            QPoint intersect = poligone.point((i-1)%poligone.size()) + t*lineVec;
            QPoint v = intersect - click;
            float distance = v.x() * v.x() + v.y() * v.y();
            //qDebug() << distance;
            if((distance < 10) && (0 <= t && t <= 1))
                return true;
        }
        return false;
    }
    return poligone.containsPoint(click,Qt::OddEvenFill);
}

void Polygone::calcBBox(QPoint &min, QPoint &max)
{
    int xMax = origin.rx(), xMin = origin.rx(), yMax = origin.ry(), yMin= origin.ry();
    QPoint p;
    for(int i = 0; i < poligone.size(); i++){
        p = poligone.point(i);
        if(xMax < p.x())
            xMax = p.x();
        else if (xMin > p.x())
            xMin = p.x();
        if (yMax < p.y())
            yMax = p.y();
        else if (yMin > p.y())
            yMin = p.y();
    }
    min = QPoint(xMin, yMin);
    max = QPoint(xMax, yMax);
}

GraphObjekt *Polygone::copy()
{
    return new Polygone(origin, color, poligone, filled);
}

void Polygone::moveTo(QPoint point)
{
    origin+=point;
    for(int i = 0; i < poligone.size(); i++)
        poligone.setPoint(i,poligone.point(i) + point);
}

bool Polygone::isValid(){
    return valid;
}
