#ifndef LINE_H
#define LINE_H

#include <QPoint>
#include "GraphObjekt.h"


class Line : public GraphObjekt
{
private:
    QPoint endPoint;

public:
    Line();
    ~Line();
    QPoint getEndPoint();
    QPoint setEndPoint();
};

#endif // LINE_H
