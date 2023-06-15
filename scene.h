#ifndef SCENE_H
#define SCENE_H
#include <queue>
#include "graphObjekt.h"


class Scene
{
    std::vector<GraphObjekt*> graphObjekts;
    GraphObjekt *currentObjekt;
    std::vector<GraphObjekt*> selectedObjects;
public:
    Scene();
    ~Scene();
    void setCurrentObjekt(GraphObjekt *graphObjekt);
    GraphObjekt* getCurrentObjekt();
    void addCurentObjektToList();
    void addGraphObjekt(GraphObjekt *graphObjekt);
    void drawAll(QPainter &painter);
    void clear();
    void addToSelected(GraphObjekt *graphobject);
    void clearSelected();
};

#endif // SCENE_H
