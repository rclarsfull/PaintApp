#include <QDebug>
#include "scene.h"

Scene::Scene():graphObjekts(),currentObjekt(nullptr), bBox(false)
{

}
Scene::~Scene()
{
    clear();
}

void Scene::setCurrentObjekt(BBoxDecorator *graphObjekt)
{
    if(currentObjekt != nullptr)
        delete currentObjekt;
    currentObjekt = graphObjekt;
}

BBoxDecorator* Scene::getCurrentObjekt()
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

void Scene::addGraphObjekt(BBoxDecorator *graphObjekt)
{
    if(graphObjekt != nullptr)
        graphObjekts.push_back(graphObjekt);
}

void Scene::drawAll(QPainter &painter)
{
    for(std::list<BBoxDecorator*>::iterator it = graphObjekts.begin();it != graphObjekts.end();it++){
        (*it)->setBBox(bBox);
        (*it)->draw(painter);
    }
    if(currentObjekt != nullptr){
        currentObjekt->setBBox(bBox);
        currentObjekt->draw(painter);
    }
}

void Scene::clear()
{
    for(std::list<BBoxDecorator*>::iterator it = graphObjekts.begin(); it != graphObjekts.end(); ){
        BBoxDecorator* tmp = *it;
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
    for(std::list<BBoxDecorator*>::reverse_iterator it = graphObjekts.rbegin();it != graphObjekts.rend(); it++){
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

void Scene::addToSelected(BBoxDecorator *graphobject)
{
    graphobject->setSelected(true);
}

void Scene::removeFromSelected(BBoxDecorator *graphobject)
{

    graphobject->setSelected(false);
}

void Scene::clearSelected()
{
    for(std::list<BBoxDecorator*>::iterator it = graphObjekts.begin(); it != graphObjekts.end(); it++){
        (*it)->setSelected(false);
    }
}

void Scene::deleteSelected()
{
    for (std::list<BBoxDecorator*>::iterator it = graphObjekts.begin(); it != graphObjekts.end();) {
        if((*it)->getSelected()){
            it = graphObjekts.erase(it);
        }else
            it++;
    }

}

void Scene::deleteLastAdded()
{
    if(!graphObjekts.empty())
        graphObjekts.pop_back();
}

void Scene::recolorSelected(QColor color)
{
    for (std::list<BBoxDecorator*>::iterator it = graphObjekts.begin(); it != graphObjekts.end();it++) {
        if((*it)->getSelected()){
            (*it)->setColor(color);
        }
    }
}

void Scene::moveObjects(QPoint point)
{
    for (std::list<BBoxDecorator*>::iterator it = graphObjekts.begin(); it != graphObjekts.end(); it++) {
        if((*it)->getSelected()){
            (*it)->moveTo(point);
        }
    }
}

void Scene::setFillForSelected(bool fill)
{
    for (std::list<BBoxDecorator*>::iterator it = graphObjekts.begin(); it != graphObjekts.end(); it++) {
        if((*it)->getSelected()){
            (*it)->setFilled(fill);
        }
    }
}

void Scene::duplicateSelected()
{
    for (std::list<BBoxDecorator*>::iterator it = graphObjekts.begin(); it != graphObjekts.end(); it++) {
        if((*it)->getSelected()){
            BBoxDecorator* graphobj = (*it)->copy();
            addGraphObjekt(graphobj);
        }
    }
}

void Scene::setBBox(bool bBox)
{
    this->bBox = bBox;
}
