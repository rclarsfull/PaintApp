#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QPoint>
#include "GraphObjekt.h"

class Triangle: public GraphObjekt
{
    QPoint qpoints[2];
public:
    Triangle();
    ~Triangle();

    void setPoint(int point);
    QPoint getPoint(int point);

};

#endif // TRIANGLE_H
