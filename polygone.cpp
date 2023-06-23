#include "polygone.h"

Polygone::Polygone(QPoint origen, QColor color):GraphObjekt(origen,color,false), points(), valid(false){}

Polygone::Polygone(QPoint origen, QColor color, std::vector<QPoint> points):GraphObjekt(origen,color,false), points(), valid(false){}

Polygone::~Polygone(){}

void Polygone::draw(QPainter &painter)
{
    if(!valid){
        painter.setPen(QPen(Qt::red,2,Qt::SolidLine));
        painter.setBrush(QBrush(Qt::SolidPattern));
        painter.drawEllipse(origin,4,4);
        for(unsigned int i = 0; i < points.size();i++){
            painter.drawEllipse(points[i],4,4);
        }
    }

    painter.setBrush(QBrush(Qt::NoBrush));
    if(filled)
        painter.setBrush(QBrush(color, Qt::SolidPattern));
    if(points.size() > 0){
        painter.setPen(QPen(color,2,Qt::SolidLine));
        painter.drawLine(origin, points.front());
        for(unsigned int i = 1; i < points.size();i++){
            painter.drawLine(points[i-1],points[i]);
        }
        if(valid)
            painter.drawLine(points.back(), origin);
        painter.setBrush(QBrush(color, Qt::NoBrush));
    }
}



bool Polygone::hit(QPoint click)
{

    QVector<QPoint*> allPoints;
    allPoints.push_back(&origin);
    for(unsigned int i = 0; i < points.size();i++)
        allPoints.push_back(&points[i]);

    for(unsigned int i = 1; i <= allPoints.size();i++){
        QPoint startToClick = click - *allPoints[(i-1)%allPoints.size()];
        QPoint lineVec = *allPoints[i%allPoints.size()] - *allPoints[(i-1)%allPoints.size()];
        float t = (float)(startToClick.x() * lineVec.x() + startToClick.y() * lineVec.y()) / (float)(lineVec.x() * lineVec.x() + lineVec.y() * lineVec.y());
        QPoint intersect = *allPoints[(i-1)%allPoints.size()] + t*lineVec;
        QPoint v = intersect - click;
        float distance = v.x() * v.x() + v.y() * v.y();
        //qDebug() << distance;
        if((distance < 10) && (0 <= t && t <= 1))
            return true;
    }
    return false;
}

void Polygone::calcBBox(QPoint &min, QPoint &max)
{


}

GraphObjekt *Polygone::copy()
{
    return new Polygone(origin, color,points); // need other construcktor
}

void Polygone::moveTo(QPoint point)
{
    origin+=point;
    for(QPoint &p:points)
        p+=point;
}


void Polygone::addPoint(QPoint point){
    QPoint vec = origin - point;
    if((vec.x()*vec.x() + vec.y()*vec.y()) > 25){
        points.push_back(point);
   }else
    valid = true;
}

bool Polygone::isValid(){
    return valid;
}
