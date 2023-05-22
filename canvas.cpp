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
	// TODO
}

void Canvas::setPrimitiveMode(int mode)
{
    type = (Canvas::PrimitiveMode)mode;
}

void Canvas::setFillMode(bool isFilled)
{
    this->FillMode = isFilled;
}

void Canvas::setObjColor(QColor color)
{
    this->color = color;
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);  // parent class draws border

    QPainter painter(this);

    // white background (inside parent's border)
    painter.fillRect(QRect(1, 1, width() - 2, height() - 2), Qt::white);

    // TODO; implement drawing functionality for all the primitives!
    // The following is just a basic example and to be removed...

    //painter.setPen(QPen(color, 2, Qt::SolidLine));
    /*
    painter.drawLine(QPoint(2, height()/2), QPoint(width()-2, height()/2));
    painter.drawLine(QPoint(width()/2, 2), QPoint(width()/2, height()-2));
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::darkGreen);
    painter.drawEllipse(QPoint(width()/2, height()/2), 8, 8);
    */
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

		// TODO; implement mouse interaction
		// Mouse position given as follows
        lastMouseClickPos = event->pos();
        lastMouseRealesePos = lastMouseClickPos;

        switch(type){
        case NONE:
            //qDebug() << "Error: no Paint type declared!\n";
            break;
        case LINE:

            break;
        case RECTANGLE:

            break;
        case CIRCLE:

            break;
        case FREE_HAND:
            scene.setCurrentObjekt(new FreeHandDrawing(lastMouseClickPos,color));
            break;
        case TRIANGLE:

            break;
        case POLYGON:

            break;

        }


        update();
	}
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
	if ((event->buttons() & Qt::LeftButton) && dragging) {

		// TODO
        qDebug() << "bewegt sich\n";
        lastMouseRealesePos = event->pos();
        switch(type){
        case NONE:
            //qDebug() << "Error: no Paint type declared!\n";
            break;
        case LINE:
            scene.setCurrentObjekt(new Line(lastMouseClickPos,lastMouseRealesePos,color));
            break;
        case RECTANGLE:

            break;
        case CIRCLE:
            scene.setCurrentObjekt(new Circle(lastMouseClickPos,lastMouseRealesePos,color));
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
        lastMouseRealesePos = event->pos();
        scene.addCurentObjektToList();

        switch(type){
        case NONE:
            //qDebug() << "Error: no Paint type declared!\n";
            break;
        case LINE:

            break;
        case RECTANGLE:

            break;
        case CIRCLE:

            break;
        case FREE_HAND:

            break;
        case TRIANGLE:

            break;
        case POLYGON:

            break;

        }

		update();
	}
}
