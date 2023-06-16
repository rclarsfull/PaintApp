#include <QDebug>
#include "scene.h"

Scene::Scene():graphObjekts(),currentObjekt(nullptr)
{

}
Scene::~Scene()
{
    clear();
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

void Scene::drawAll(QPainter &painter)
{

    for(unsigned int i = 0;i < graphObjekts.size();i++){
        if(graphObjekts.at(i) != nullptr)
            graphObjekts[i]->draw(painter);
    }
    if(currentObjekt != nullptr)
        currentObjekt->draw(painter);
}

void Scene::clear()
{
    for(unsigned int i = 0; i < graphObjekts.size(); i++){
        if(graphObjekts.at(i) != nullptr){
           delete graphObjekts[i];
           graphObjekts[i] = nullptr;
        }
    }
    if(currentObjekt != nullptr){
        delete currentObjekt;
        currentObjekt = nullptr;
    }
}

void Scene::checkforHit(QPoint click)
{
    for(int i = graphObjekts.size() - 1; i >= 0; i--){
        if(graphObjekts.at(i) != nullptr && graphObjekts.at(i)->hit(click)){
           if(graphObjekts.at(i)->getSelected()){
               removeFromSelected(graphObjekts.at(i));
               break;
           }else{
               addToSelected(graphObjekts.at(i));
               break;
           }
        }
    }
}

void Scene::addToSelected(GraphObjekt *graphobject)
{
    selectedObjects.push_back(graphobject);
    graphobject->setSelected(true);
}

void Scene::removeFromSelected(GraphObjekt *graphobject)
{
    selectedObjects.remove(graphobject);
    graphobject->setSelected(false);
}

void Scene::clearSelected()
{
    selectedObjects.clear();
}
