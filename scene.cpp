#include "scene.h"

Scene::Scene():graphObjekts(),currentObjekt(nullptr)
{

}

void Scene::setCurrentObjekt(GraphObjekt *graphObjekt)
{
    if(currentObjekt != nullptr)
        delete currentObjekt;
    currentObjekt = graphObjekt;
}

void Scene::addCurentObjektToList()
{
    if(currentObjekt != nullptr){
        graphObjekts.push_back(currentObjekt);
        currentObjekt = nullptr;
    }
}

void Scene::addGraphObjekt(GraphObjekt *graphObjekt)
{
    if(graphObjekt != nullptr)
        graphObjekts.push_back(graphObjekt);
}

void Scene::drawAll(QPainter &painter)
{
    for(int i = 0;i < graphObjekts.size();i++){
        graphObjekts.at(i)->draw(painter);
    }
    if(currentObjekt != nullptr)
        currentObjekt->draw(painter);
}
