#ifndef SCENE_H
#define SCENE_H
#include <queue>
#include <QPoint>
#include "BBoxDecorator.h"

class Scene
{
    std::list<BBoxDecorator*> graphObjekts;
    BBoxDecorator *currentObjekt;
    //std::list<GraphObjekt*> selectedObjects;
public:
    Scene();
    ~Scene();
    void setCurrentObjekt(BBoxDecorator *graphObjekt);
    BBoxDecorator* getCurrentObjekt();
    void addCurentObjektToList();
    void addGraphObjekt(BBoxDecorator *graphObjekt);
    void drawAll(QPainter &painter);
    void clear();

    void checkforHit(QPoint click);
    void clearSelected();
    void deleteSelected();
    void recolorSelected(QColor color);
    void moveObjects(QPoint point);
    void setFillForSelected(bool fill);
    void duplicateSelected();
    void setBBox(bool bBox);
private:
    void addToSelected(BBoxDecorator *graphobject);
    void removeFromSelected(BBoxDecorator *graphobject);
    bool bBox;
};

#endif // SCENE_H
