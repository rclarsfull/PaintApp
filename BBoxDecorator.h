#ifndef BBOXDECORATOR_H
#define BBOXDECORATOR_H

#include "graphObjekt.h"

class BBoxDecorator: GraphObjekt{
public:
    GraphObjekt *getGraphObj() const;
    void calcBBox(QPoint &min, QPoint &max) override;
private:
    GraphObjekt *graphObj;
};

#endif // BBOXDECORATOR_H
