#include "polygone.h"

Polygone::Polygone(QPoint origen, QColor color):GraphObjekt(origen,color,false), points(), valid(false){}

Polygone::Polygone(QPoint origen, QColor color, std::vector<QPoint> points):GraphObjekt(origen,color,false), points(points), valid(true){}

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
    if(points.size() > 0){
        painter.setPen(QPen(color,2,Qt::SolidLine));
        painter.drawLine(origin, points.front());
        for(unsigned int i = 1; i < points.size();i++)
            painter.drawLine(points[i-1],points[i]);
        if(valid)
            painter.drawLine(points.back(), origin);
        painter.setBrush(QBrush(color, Qt::NoBrush));
    }
    if(selected && points.size() > 0){
        painter.setPen(QPen(QColor("red"),5, Qt::DashLine));
        painter.drawLine(origin, points.front());
            for(unsigned int i = 1; i < points.size();i++)
                painter.drawLine(points[i-1],points[i]);
            if(valid)
                painter.drawLine(points.back(), origin);
            painter.setBrush(QBrush(color, Qt::NoBrush));

    }
}

void Polygone::update(QPoint newPoint)
{
    QPoint vec = origin - newPoint;
    if((vec.x()*vec.x() + vec.y()*vec.y()) > 25){
            points.push_back(newPoint);
    }else
            valid = true;
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
    int xMax = origin.rx(), xMin = origin.rx(), yMax = origin.ry(), yMin= origin.ry();
    for(QPoint p:points){
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
    return new Polygone(origin, color, points);
}

void Polygone::moveTo(QPoint point)
{
    origin+=point;
    for(QPoint &p:points)
        p+=point;
}

bool Polygone::isValid(){
    return valid;
}
