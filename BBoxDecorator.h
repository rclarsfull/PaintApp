#ifndef BBOXDECORATOR_H
#define BBOXDECORATOR_H

#include "graphObjekt.h"

class BBoxDecorator: GraphObjekt{
public:
    GraphObjekt *getGraphObj() const{return graphObj;}

private:
    GraphObjekt *graphObj;
};

#endif // BBOXDECORATOR_H
