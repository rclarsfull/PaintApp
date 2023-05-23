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
    void setOrigin(QPoint point);
    QPoint getOrigin();
    void draw(QPainter &painter);
    void deleteWhenConnected(QPoint selected) override;
};

#endif // LINE_H
