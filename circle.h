#ifndef CIRCLE_H
#define CIRCLE_H

#include "GraphObjekt.h"


class Circle: public GraphObjekt
{
private:
    QPoint outerPoint;
public:
    Circle();
};

#endif // CIRCLE_H
