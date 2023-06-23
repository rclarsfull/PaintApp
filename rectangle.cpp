#include <QDebug>
#include "rectangle.h"

Rectangle::Rectangle(QPoint origen, QPoint lowerRightCorner, QColor color, bool filled):GraphObjekt(origen,color, filled), lowerRightCorner(lowerRightCorner){}

Rectangle::~Rectangle(){}

void Rectangle::draw(QPainter &painter)
{
    if(filled)
        painter.setBrush(QBrush(color, Qt::SolidPattern));

    painter.setPen(QPen(color,2, Qt::SolidLine));
    int width = lowerRightCorner.x() - origin.x();
    int height = lowerRightCorner.y() - origin.y();
    painter.drawRect(origin.x(), origin.y(), width, height);
    painter.setBrush(QBrush(color, Qt::NoBrush));
    if(selected){
        painter.setPen(QPen(QColor("red"),5, Qt::DashLine));
        painter.drawRect(origin.x(), origin.y(), width, height);
    }
}

void Rectangle::update(QPoint newPoint)
{
    lowerRightCorner = newPoint;
}

bool Rectangle::isNoSizeObjekt()
{
    return(origin == lowerRightCorner);
}

bool Rectangle::hit(QPoint click)
{
    bool xIn = (click.x() < origin.x() && click.x() > lowerRightCorner.x()) || (click.x() > origin.x() && click.x() < lowerRightCorner.x());
    bool yIn = (click.y() < origin.y() && click.y() > lowerRightCorner.y()) || (click.y() > origin.y() && click.y() < lowerRightCorner.y());
    if(filled){
        return xIn && yIn;
    }else{
        bool onX = (click.x() < origin.x() + 10 && click.x() > origin.x() - 10) || (click.x() < lowerRightCorner.x() + 10 && click.x() > lowerRightCorner.x() - 10);
        bool onY = (click.y() < origin.y() + 10 && click.y() > origin.y() - 10) || (click.y() < lowerRightCorner.y() + 10 && click.y() > lowerRightCorner.y() - 10);
        return (xIn && onY) || (yIn && onX);
    }
}

void Rectangle::moveTo(QPoint point)
{
    origin = origin + point;
    lowerRightCorner = lowerRightCorner + point;
}

GraphObjekt *Rectangle::copy()
{
    return new Rectangle(origin, lowerRightCorner, color, filled);
}

void Rectangle::calcBBox(QPoint &min, QPoint &max)
{
    min = origin;
    max = lowerRightCorner;
}
