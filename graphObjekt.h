#ifndef GRAPHOBJEKT_H
#define GRAPHOBJEKT_H
#include <QPoint>

class GraphObjekt{
    GraphObjekt();
    ~GraphObjekt();
public:
    virtual QPoint getOrigin() = 0;
    virtual QPoint setOrigin() = 0;
protected:
    QPoint orign;

};

#endif // GRAPHOBJEKT_H
