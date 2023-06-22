#ifndef SCENE_H
#define SCENE_H
#include <queue>
#include <QPoint>
#include "graphObjekt.h"


class Scene
{
    std::list<GraphObjekt*> graphObjekts;
    GraphObjekt *currentObjekt;
    //std::list<GraphObjekt*> selectedObjects;
public:
    Scene();
    ~Scene();
    void setCurrentObjekt(GraphObjekt *graphObjekt);
    GraphObjekt* getCurrentObjekt();
    void addCurentObjektToList();
    void addGraphObjekt(GraphObjekt *graphObjekt);
    void drawAll(QPainter &painter);
    void clear();

    void checkforHit(QPoint click);
    void clearSelected();
    void deleteSelected();
    void recolorSelected(QColor color);
    void moveObjects(QPoint point);
private:
    void addToSelected(GraphObjekt *graphobject);
    void removeFromSelected(GraphObjekt *graphobject);
};

#endif // SCENE_H
