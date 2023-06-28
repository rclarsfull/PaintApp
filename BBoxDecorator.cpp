#include "BBoxDecorator.h"

BBoxDecorator::BBoxDecorator(GraphObjekt *graphObject): GraphObjekt(*graphObject), graphObj(graphObject){}

GraphObjekt *BBoxDecorator::getGraphObj() const
{
    return graphObj;
}

void BBoxDecorator::draw(QPainter &painter)
{
    graphObj->draw(painter);
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

GraphObjekt *BBoxDecorator::copy()
{
    GraphObjekt *g = graphObj->copy();
    return new BBoxDecorator(g);
}

void BBoxDecorator::calcBBox(QPoint &min, QPoint &max)
{
    graphObj->calcBBox(min, max);
}
