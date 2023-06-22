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

    for(std::list<GraphObjekt*>::iterator it = graphObjekts.begin();it != graphObjekts.end();it++){
        (*it)->draw(painter);
    }
    if(currentObjekt != nullptr)
        currentObjekt->draw(painter);
}

void Scene::clear()
{
    for(std::list<GraphObjekt*>::iterator it = graphObjekts.begin(); it != graphObjekts.end(); ){
        GraphObjekt* tmp = *it;
        it = graphObjekts.erase(it);
        delete tmp;
    }
    if(currentObjekt != nullptr){
        delete currentObjekt;
        currentObjekt = nullptr;
    }
}

void Scene::checkforHit(QPoint click)
{
    for(std::list<GraphObjekt*>::reverse_iterator it = graphObjekts.rbegin();it != graphObjekts.rend(); it++){
        if(*it != nullptr && (*it)->hit(click)){
            if((*it)->getSelected()){
                removeFromSelected(*it);
                break;
            }else{
                addToSelected(*it);
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
    for (std::list<GraphObjekt*>::iterator it = selectedObjects.begin(); it != selectedObjects.end(); ++it) {
        (*it)->setSelected(false);
    }
    selectedObjects.clear();
}

void Scene::deleteSelected()
{
    for (std::list<GraphObjekt*>::iterator yt = graphObjekts.begin(); yt != graphObjekts.end(); ) {
        for(std::list<GraphObjekt*>::iterator it = selectedObjects.begin(); it != selectedObjects.end(); it++){
            if(*yt == *it){
                GraphObjekt* tmp = *yt;
                yt = graphObjekts.erase(yt);
                delete tmp;
               // --yt;
            }
        }
    }
    clearSelected();
}

void Scene::recolorSelected(QColor color)
{
    for (std::list<GraphObjekt*>::iterator it = selectedObjects.begin(); it != selectedObjects.end(); it++) {
        (*it)->setColor(color);
    }
}

void Scene::moveObjects(QPoint point)
{
    for (std::list<GraphObjekt*>::iterator it = selectedObjects.begin(); it != selectedObjects.end(); it++) {
        (*it)->moveTo(point);
    }
}
