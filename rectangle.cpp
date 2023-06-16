#include <QDebug>
#include "rectangle.h"

Rectangle::Rectangle(QPoint origen, QPoint lowerRightCorner, QColor color, bool filled):GraphObjekt(origen,color), lowerRightCorner(lowerRightCorner), filled(filled)
{

}

Rectangle::~Rectangle()
{

}

void Rectangle::setPoint(int point)
{

}

QPoint Rectangle::getPoint(int point)
{

}

void Rectangle::setOrigin(QPoint point)
{

}

QPoint Rectangle::getOrigin()
{

}

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

void Rectangle::deleteWhenConnected(QPoint selected)
{

}

void Rectangle::update(QPoint newPoint)
{
    lowerRightCorner = newPoint;
}

bool Rectangle::equalPoints()
{

}

bool Rectangle::hit(QPoint click)
{
    bool xIn = xIn = (click.x() < origin.x() && click.x() > lowerRightCorner.x()) || (click.x() > origin.x() && click.x() < lowerRightCorner.x());
    bool yIn = yIn = (click.y() < origin.y() && click.y() > lowerRightCorner.y()) || (click.y() > origin.y() && click.y() < lowerRightCorner.y());
    if(filled){
        return xIn && yIn;
    }else{
        bool onX = (click.x() + 10 > origin.x() && click.x() - 10 < origin.x()) || (click.x() + 10 > lowerRightCorner.x() && click.x() - 10 < lowerRightCorner.x());
        bool onY = (click.y() + 10 > origin.y() && click.y() - 10 < origin.y()) || (click.y() + 10 > lowerRightCorner.y() && click.y() - 10 < lowerRightCorner.y());
        return (xIn && onY) || (yIn && onX);
    }

}

void Rectangle::moveTo(QPoint point)
{
    origin = origin + point;
    lowerRightCorner = lowerRightCorner + point;
}
