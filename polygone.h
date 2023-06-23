#ifndef POLYGONE_H
#define POLYGONE_H
#include "graphObjekt.h"


class Polygone: public GraphObjekt
{
    std::vector<QPoint> points;
    bool valid;
public:
    Polygone(QPoint origen, QColor color);
    Polygone(const Polygone&) = delete;
    Polygone& operator=(const Polygone&) = delete;
    ~Polygone();
    void draw(QPainter &painter) override;
    bool equalPoints() override;
    bool hit(QPoint click) override;
    void calcBBox(QPoint &min, QPoint &max) override;
    GraphObjekt* copy() override;
    void moveTo(QPoint point) override;
    void addPoint(QPoint point);
    bool isValid() override;
};

#endif // POLYGONE_H
