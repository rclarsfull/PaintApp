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
    int width = lowerRightCorner.x() - orign.x();
    int height = lowerRightCorner.y() - orign.y();
    painter.drawRect(orign.x(), orign.y(), width, height);
    painter.setBrush(QBrush(color, Qt::NoBrush));
}

void Rectangle::deleteWhenConnected(QPoint selected)
{

}
