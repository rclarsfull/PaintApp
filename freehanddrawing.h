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
    FreeHandDrawing(QPoint origen, QColor color);
    FreeHandDrawing(const FreeHandDrawing&) = delete;
    FreeHandDrawing& operator=(const FreeHandDrawing&) = delete;
    ~FreeHandDrawing();
    void draw(QPainter &painter) override;
    void addPoint(QPoint point);
    void setOrigin(QPoint point) override;
    QPoint getOrigin() override;
    void deleteWhenConnected(QPoint selected) override;
    void update(QPoint newPoint) override;
    bool equalPoints() override;
    bool hit(QPoint click) override;
};

#endif // FREEHANDDRAWING_H
