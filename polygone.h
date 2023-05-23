#ifndef POLYGONE_H
#define POLYGONE_H
#include "graphObjekt.h"


class Polygone: public GraphObjekt
{
public:
    Polygone(QPoint origen, QColor color);
    ~Polygone();
    void setOrigin(QPoint point);
    QPoint getOrigin();
    void draw(QPainter &painter);
    void deleteWhenConnected(QPoint selected) override;
};

#endif // POLYGONE_H
