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
}

void Rectangle::deleteWhenConnected(QPoint selected)
{

}

void Rectangle::update(QPoint newPoint)
{
    lowerRightCorner = newPoint;
}
