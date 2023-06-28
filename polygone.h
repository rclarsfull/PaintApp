#ifndef POLYGONE_H
#define POLYGONE_H
#include "graphObjekt.h"


class Polygone: public GraphObjekt
{
    //std::vector<QPoint> points;
    bool valid;
    QPolygon poligone;
public:
    Polygone(QPoint origen, QColor color, bool filled);
    Polygone(QPoint origen, QColor color, QPolygon poligone, bool filled);
    Polygone(const Polygone&) = delete;
    Polygone& operator=(const Polygone&) = delete;
    ~Polygone();
    void draw(QPainter &painter) override;
    void update(QPoint newPoint) override;
    bool hit(QPoint click) override;
    void calcBBox(QPoint &min, QPoint &max) override;
    GraphObjekt* copy() override;
    void moveTo(QPoint point) override;
    bool isValid() override;
};

#endif // POLYGONE_H
