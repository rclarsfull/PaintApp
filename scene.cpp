#include "scene.h"

Scene::Scene():graphObjekts(),currentObjekt(nullptr)
{

}
Scene::~Scene()
{
    for(int i = 0;i < graphObjekts.size();i++){
        if(graphObjekts.at(i) != nullptr)
           delete graphObjekts[i];
    }
    if(currentObjekt != nullptr)
        delete currentObjekt;
}

void Scene::setCurrentObjekt(GraphObjekt *graphObjekt)
{
    if(currentObjekt != nullptr)
        delete currentObjekt;
    currentObjekt = graphObjekt;
}

GraphObjekt* Scene::getCurrentObjekt()
{
    return currentObjekt;
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

void Scene::removeAllGraphobjects()
{
    currentObjekt = nullptr;
    for (unsigned int i = 0; i < graphObjekts.size(); ++i) {
        if(graphObjekts.at(i) != nullptr)
           delete graphObjekts.at(i);
        graphObjekts.at(i) = nullptr;
    }
}

void Scene::drawAll(QPainter &painter)
{
    for(unsigned int i = 0;i < graphObjekts.size();i++){
        if(graphObjekts.at(i) != nullptr)
            graphObjekts.at(i)->draw(painter);
    }
    if(currentObjekt != nullptr)
        currentObjekt->draw(painter);
}
