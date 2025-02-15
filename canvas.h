#ifndef CANVAS_H
#define CANVAS_H

#include <QFrame>
#include "scene.h"

class Canvas : public QFrame
{
	Q_OBJECT

public:
	enum PrimitiveMode {
        NONE, FREE_HAND, CIRCLE, LINE, TRIANGLE, RECTANGLE, POLYGON
	};
    enum InteractionMode {
        CREATE, SELECT, MOVEOBJ
    };

	Canvas(QWidget *parent = 0);
	~Canvas();

	QSize minimumSizeHint() const;
	QSize sizeHint() const;

	void setPrimitiveMode(int mode);
    void setInteractionMode(int mode);

    void setFillMode(bool isFilled);
    void setObjColor(QColor color);
    Scene* getScene();

protected:
	void paintEvent(QPaintEvent *event);
	void resizeEvent(QResizeEvent *event);

	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);

private:
	bool dragging;
	PrimitiveMode type;
    InteractionMode mode;
    QPoint lastMouseClickPos;
    QPoint lastMouseRealesePos;
    Scene scene;
    bool fillMode;
    QColor color;
};

#endif // CANVAS_H
