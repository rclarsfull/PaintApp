#ifndef SCENE_H
#define SCENE_H
#include <queue>
#include "GraphObjekt.h"


class Scene
{
    std::vector<GraphObjekt> graphObjekts;
public:
    Scene();
    void addGraphObjekt();
    void removeGraphobjekt();
    void drawAll(QPainter &painter);

};

#endif // SCENE_H
