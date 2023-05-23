#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <math.h>
#include "canvas.h"
#include "freehanddrawing.h"
#include "graphObjekt.h"
#include "line.h"
#include "circle.h"

Canvas::Canvas(QWidget *parent)
    : QFrame(parent),scene(Scene())
{
	setFrameStyle(QFrame::Box);
	setMouseTracking(true);

    type = NONE;
	dragging = false;
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

void Canvas::clearCanvas(void)
{
    scene.clear();
}

void Canvas::setPrimitiveMode(int mode)
{
    type = (Canvas::PrimitiveMode)mode;
}

void Canvas::setFillMode(bool isFilled)
{
    fillMode = isFilled;
}

void Canvas::setObjColor(QColor color)
{
    this->color = color;
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

        switch(type){
        case NONE:
            qDebug() << "Error: no Paint type declared!\n";
            break;
        case LINE:

            break;
        case RECTANGLE:
            qDebug() << "Not implemented!\n";
            break;
        case CIRCLE:

            break;
        case FREE_HAND:
            scene.setCurrentObjekt(new FreeHandDrawing(lastMouseClickPos,color));
            break;
        case TRIANGLE:
            qDebug() << "Not implemented!\n";
            break;
        case POLYGON:
            qDebug() << "Not implemented!\n";
            break;
        }

        update();
	}
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
	if ((event->buttons() & Qt::LeftButton) && dragging) {

        switch(type){
        case NONE:

            break;
        case LINE:
            scene.setCurrentObjekt(new Line(lastMouseClickPos,event->pos(),color));
            break;
        case RECTANGLE:

            break;
        case CIRCLE:
            scene.setCurrentObjekt(new Circle(lastMouseClickPos,event->pos(),color,fillMode));
            break;
        case FREE_HAND:
            dynamic_cast<FreeHandDrawing*>(scene.getCurrentObjekt())->addPoint(event->pos());
            break;
        case TRIANGLE:

            break;
        case POLYGON:

            break;
        }
        update();
    }
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && dragging) {
		dragging = false;
        scene.addCurentObjektToList();
		update();
	}
}
