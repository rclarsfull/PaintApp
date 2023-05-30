#ifndef FREEHANDDRAWING_H
#define FREEHANDDRAWING_H

#include <QPainter>
#include <QPoint>
#include <vector>
#include "GraphObjekt.h"


class FreeHandDrawing: public GraphObjekt
{
    std::vector<QPoint> points;
public:
    FreeHandDrawing(QPoint origen, QColor color);
    ~FreeHandDrawing();
    void draw(QPainter &painter) override;
    void addPoint(QPoint point);
    void setOrigin(QPoint point) override;
    QPoint getOrigin() override;
    void deleteWhenConnected(QPoint selected) override;
    void update(QPoint newPoint) override;
    bool equalPoints() override;
};

#endif // FREEHANDDRAWING_H
