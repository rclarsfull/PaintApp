#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <math.h>
#include "canvas.h"

Canvas::Canvas(QWidget *parent)
	: QFrame(parent)
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

void Canvas::paintEvent(QPaintEvent *event)
{
    QFrame::paintEvent(event);  // parent class draws border

    QPainter painter(this);

    // white background (inside parent's border)
    painter.fillRect(QRect(1, 1, width() - 2, height() - 2), Qt::white);

    // TODO; implement drawing functionality for all the primitives!
    // The following is just a basic example and to be removed...
    /*
    painter.setPen(QPen(Qt::red, 2, Qt::SolidLine));
    painter.drawLine(QPoint(2, height()/2), QPoint(width()-2, height()/2));
    painter.drawLine(QPoint(width()/2, 2), QPoint(width()/2, height()-2));
    painter.setPen(Qt::blue);
    painter.setBrush(Qt::darkGreen);
    painter.drawEllipse(QPoint(width()/2, height()/2), 8, 8);
    */
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
		//QPoint currPos = event->pos();

		update();
	}
}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{
	if ((event->buttons() & Qt::LeftButton) && dragging) {

		// TODO

		update();
	}
}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton && dragging) {
		dragging = false;

		// TODO

		update();
	}
}
