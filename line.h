#ifndef LINE_H
#define LINE_H

#include <QPoint>
#include <QLine>
#include "graphObjekt.h"


class Line : public GraphObjekt
{
private:
    QPoint endPoint;

public:
    Line(QPoint beginPoint,QPoint endPoint, QColor color);
    Line(const Line&) = delete;
    Line& operator=(const Line&) = delete;
    ~Line();
    void draw(QPainter &painter) override;
    void update(QPoint newPoint) override;
    bool equalPoints() override;
    bool hit(QPoint click) override;
    void moveTo(QPoint point) override;
};

#endif // LINE_H
