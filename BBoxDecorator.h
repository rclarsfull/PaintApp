#ifndef BBOXDECORATOR_H
#define BBOXDECORATOR_H

#include "graphObjekt.h"

class BBoxDecorator: GraphObjekt{
public:
    BBoxDecorator(GraphObjekt *graphObject);
    GraphObjekt *getGraphObj() const;
    void draw(QPainter &painter) override;
    void update(QPoint newPoint) override;
    bool hit(QPoint click) override;
    void moveTo(QPoint point) override;
    GraphObjekt* copy() override;
    void calcBBox(QPoint &min, QPoint &max) override;
private:
    GraphObjekt *graphObj;
};

#endif // BBOXDECORATOR_H
