#include "BBoxDecorator.h"

GraphObjekt *BBoxDecorator::getGraphObj() const
{
    return graphObj;
}

void BBoxDecorator::calcBBox(QPoint &min, QPoint &max)
{
    graphObj->calcBBox(min, max);
}
