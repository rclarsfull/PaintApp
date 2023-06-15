#ifndef SCENE_H
#define SCENE_H
#include <queue>
#include "graphObjekt.h"


class Scene
{
    std::vector<GraphObjekt*> graphObjekts;
    GraphObjekt *currentObjekt;
public:
    Scene();
    ~Scene();
    void setCurrentObjekt(GraphObjekt *graphObjekt);
    GraphObjekt* getCurrentObjekt();
    void addCurentObjektToList();
    void addGraphObjekt(GraphObjekt *graphObjekt);
    void removeGraphobjekt(GraphObjekt *graphObjekt);
    void drawAll(QPainter &painter);
    void clear();
};

#endif // SCENE_H
