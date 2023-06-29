#include "BBoxDecorator.h"

BBoxDecorator::BBoxDecorator(GraphObjekt *graphObject): GraphObjekt(*graphObject), graphObj(graphObject), bBox(false){}

BBoxDecorator::~BBoxDecorator()
{
    delete graphObj;
}

GraphObjekt *BBoxDecorator::getGraphObj() const
{
    return graphObj;
}

void BBoxDecorator::draw(QPainter &painter)
{
    graphObj->draw(painter);
    if(bBox){
        QPoint min, max;
        graphObj->calcBBox(min, max);
        QPoint vec = max - min;
        painter.setPen(QPen(QColor("gray"),5, Qt::DashLine));
        painter.setBrush(Qt::NoBrush);
        painter.drawRect(min.x(), min.y(), vec.x(), vec.y());
    }
}

void BBoxDecorator::update(QPoint newPoint)
{
    graphObj->update(newPoint);
}

bool BBoxDecorator::hit(QPoint click)
{
    return graphObj->hit(click);
}

void BBoxDecorator::moveTo(QPoint point)
{
    graphObj->moveTo(point);
}

BBoxDecorator *BBoxDecorator::copy()
{
    GraphObjekt *g = graphObj->copy();
    return new BBoxDecorator(g);
}

void BBoxDecorator::calcBBox(QPoint &min, QPoint &max)
{
    graphObj->calcBBox(min, max);
}

bool BBoxDecorator::isValid()
{
    return graphObj->isValid();
}

bool BBoxDecorator::isNoSizeObjekt()
{
    return graphObj->isNoSizeObjekt();
}

void BBoxDecorator::setSelected(bool b)
{
    graphObj->setSelected(b);
}

bool BBoxDecorator::getSelected()
{
    return graphObj->getSelected();
}

void BBoxDecorator::setColor(QColor color)
{
    graphObj->setColor(color);
}

bool BBoxDecorator::getFilled()
{
    return graphObj->getFilled();
}

void BBoxDecorator::setFilled(bool filled)
{
    graphObj->setFilled(filled);
}

void BBoxDecorator::setBBox(bool newBBox)
{
    bBox = newBBox;
}
