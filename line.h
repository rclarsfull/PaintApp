#ifndef LINE_H
#define LINE_H

#include <QPoint>
#include <QLine>
#include "GraphObjekt.h"


class Line : public GraphObjekt
{
private:
    QPoint endPoint;

public:
    Line(QPoint beginPoint,QPoint endPoint, QColor color);
    ~Line();
    QPoint getEndPoint();
    void setEndPoint();
    void setOrigin(QPoint point) override;
    QPoint getOrigin() override;
    void draw(QPainter &painter) override;
    void deleteWhenConnected(QPoint selected) override;
    void update(QPoint newPoint) override;
};

#endif // LINE_H
