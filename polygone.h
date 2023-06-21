#ifndef POLYGONE_H
#define POLYGONE_H
#include "graphObjekt.h"


class Polygone: public GraphObjekt
{
public:
    Polygone(QPoint origen, QColor color);
    Polygone(const Polygone&) = delete;
    Polygone& operator=(const Polygone&) = delete;
    ~Polygone();
    void draw(QPainter &painter) override;
    void update(QPoint newPoint) override;
    bool equalPoints() override;
};

#endif // POLYGONE_H
