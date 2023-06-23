#ifndef FREEHANDDRAWING_H
#define FREEHANDDRAWING_H

#include <QPainter>
#include <QPoint>
#include <vector>
#include "graphObjekt.h"


class FreeHandDrawing: public GraphObjekt
{
    std::vector<QPoint> points;
public:
    FreeHandDrawing(QPoint origin, QColor color);
    FreeHandDrawing(QPoint origin, QColor color, std::vector<QPoint> points);
    FreeHandDrawing(const FreeHandDrawing&) = delete;
    FreeHandDrawing& operator=(const FreeHandDrawing&) = delete;
    ~FreeHandDrawing();
    void draw(QPainter &painter) override;
    void addPoint(QPoint point);
    void update(QPoint newPoint) override;
    bool equalPoints() override;
    bool hit(QPoint click) override;
    void moveTo(QPoint point) override;
    GraphObjekt* copy() override;
};

#endif // FREEHANDDRAWING_H
