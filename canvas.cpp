#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <QKeyEvent>
#include <math.h>
#include "canvas.h"
#include "freehanddrawing.h"
#include "graphObjekt.h"
#include "line.h"
#include "circle.h"
#include "polygone.h"
#include "rectangle.h"
#include "BBoxDecorator.h"

Canvas::Canvas(QWidget *parent)
    : QFrame(parent),scene(Scene())
{
    setFrameStyle(QFrame::Box);
    setMouseTracking(true);

    type = NONE;
    dragging = false;
    mode = CREATE;
}

Canvas::~Canvas()
{
}

QSize Canvas::minimumSizeHint() const
{
    return QSize(200, 200);
}

QSize Canvas::sizeHint() const
{
    return QSize(640, 480);
}

void Canvas::setPrimitiveMode(int mode)
{
    type = (Canvas::PrimitiveMode)mode;
}

void Canvas::setInteractionMode(int mode)
{
    this->mode = (Canvas::InteractionMode)mode;
    scene.setCurrentObjekt(nullptr);
    update();
}

void Canvas::setFillMode(bool isFilled)
{
    fillMode = isFilled;
}

void Canvas::setObjColor(QColor color)
{
    this->color = color;
    scene.recolorSelected(color);
}

Scene *Canvas::getScene()
{
    return &scene;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);
    QPainter painter(this);
    painter.fillRect(QRect(1, 1, width() - 2, height() - 2), Qt::white);
    scene.drawAll(painter);
}

void Canvas::resizeEvent(QResizeEvent *event) 
{
    QFrame::resizeEvent(event);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        dragging = true;
        lastMouseClickPos = event->pos();

        BBoxDecorator *bBoxDecorator = nullptr;

        switch (mode) {
        case CREATE:
            switch(type){
            case NONE:
                qDebug() << "Error: no Paint type declared!\n";
                break;
            case LINE:
                bBoxDecorator = new BBoxDecorator(new Line(lastMouseClickPos, lastMouseClickPos, color));
                scene.setCurrentObjekt(bBoxDecorator);
                //scene.setCurrentObjekt(new Line(lastMouseClickPos, lastMouseClickPos, color));
                break;
            case RECTANGLE:
                bBoxDecorator = new BBoxDecorator(new Rectangle(lastMouseClickPos, lastMouseClickPos, color, fillMode));
                scene.setCurrentObjekt(bBoxDecorator);
                //scene.setCurrentObjekt(new Rectangle(lastMouseClickPos, lastMouseClickPos, color, fillMode));
                break;
            case CIRCLE:
                bBoxDecorator = new BBoxDecorator(new Circle(lastMouseClickPos, lastMouseClickPos, color, fillMode));
                scene.setCurrentObjekt(bBoxDecorator);
                //scene.setCurrentObjekt(new Circle(lastMouseClickPos, lastMouseClickPos, color, fillMode));
                break;
            case FREE_HAND:
                bBoxDecorator = new BBoxDecorator(new FreeHandDrawing(lastMouseClickPos,color));
                scene.setCurrentObjekt(bBoxDecorator);
                //scene.setCurrentObjekt(new FreeHandDrawing(lastMouseClickPos,color));
                break;
            case TRIANGLE:
                qDebug() << "Not implemented!\n";
                break;
            case POLYGON:
                if(scene.getCurrentObjekt() == nullptr){
                    bBoxDecorator = new BBoxDecorator(new Polygone(lastMouseClickPos,color,fillMode));
                    scene.setCurrentObjekt(bBoxDecorator);
                //scene.setCurrentObjekt(new Polygone(lastMouseClickPos,color));
                }
                else
                    scene.getCurrentObjekt()->update(event->pos());
                break;
            }
            update();
            break;
        case SELECT:
            scene.checkforHit(lastMouseClickPos);
            break;
        case MOVEOBJ:

            break;
        default:
            break;
        }
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && dragging) {

        switch (mode) {
        case CREATE:
            switch(type){
            case NONE:

                break;
            case LINE:
                scene.getCurrentObjekt()->update(event->pos());
                break;
            case RECTANGLE:
                scene.getCurrentObjekt()->update(event->pos());
                break;
            case CIRCLE:
                scene.getCurrentObjekt()->update(event->pos());
                break;
            case FREE_HAND:
                scene.getCurrentObjekt()->update(event->pos());
                break;
            case TRIANGLE:
                break;
            case POLYGON:
                break;
            }
            break;
        case SELECT:

            break;
        case MOVEOBJ:
        {
            QPoint moveVec = event->pos() - lastMouseClickPos;
            lastMouseClickPos = event->pos();
            scene.moveObjects(moveVec);
            break;
        }
        default:
            break;
        }
        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && dragging) {
        dragging = false;
        if(scene.getCurrentObjekt() != nullptr && scene.getCurrentObjekt()->isValid()){
            if(!scene.getCurrentObjekt()->isNoSizeObjekt())
              scene.addCurentObjektToList();
            scene.setCurrentObjekt(nullptr);
        }
        update();
    }
}

void Canvas::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Backspace){
        if(event->keyCombination() == QKeyCombination(Qt::SHIFT, Qt::Key_Backspace))
            scene.clear();
        else
            scene.deleteSelected();
    }
    update();
}
