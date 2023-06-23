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
    graphobject->setSelected(true);
}

void Scene::removeFromSelected(GraphObjekt *graphobject)
{

    graphobject->setSelected(false);
}

void Scene::clearSelected()
{
    for(std::list<GraphObjekt*>::iterator it = graphObjekts.begin(); it != graphObjekts.end(); it++){
        (*it)->setSelected(false);
    }
}

void Scene::deleteSelected()
{
    for (std::list<GraphObjekt*>::iterator it = graphObjekts.begin(); it != graphObjekts.end();) {
        if((*it)->getSelected()){
            it = graphObjekts.erase(it);
        }else
            it++;
    }

}

void Scene::recolorSelected(QColor color)
{
    for (std::list<GraphObjekt*>::iterator it = graphObjekts.begin(); it != graphObjekts.end();it++) {
        if((*it)->getSelected()){
            (*it)->setColor(color);
        }
    }
}

void Scene::moveObjects(QPoint point)
{
    for (std::list<GraphObjekt*>::iterator it = graphObjekts.begin(); it != graphObjekts.end(); it++) {
        if((*it)->getSelected()){
            (*it)->moveTo(point);
        }
    }
}

void Scene::setFillForSelected(bool fill)
{
    for (std::list<GraphObjekt*>::iterator it = graphObjekts.begin(); it != graphObjekts.end(); it++) {
        if((*it)->getSelected()){
            (*it)->setFilled(fill);
        }
    }
}

void Scene::duplicateSelected()
{
    for (std::list<GraphObjekt*>::iterator it = graphObjekts.begin(); it != graphObjekts.end(); it++) {
        if((*it)->getSelected()){
            GraphObjekt* graphobj = (*it)->copy();
            addGraphObjekt(graphobj);
        }
    }
}
