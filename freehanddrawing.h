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
    void draw(QPainter &painter);
    void addPoint(QPoint point);
    void setOrigin(QPoint point);
    QPoint getOrigin();
    void deleteWhenConnected(QPoint selected) override;
};

#endif // FREEHANDDRAWING_H
