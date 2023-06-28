#ifndef BBOXDECORATOR_H
#define BBOXDECORATOR_H

#include "graphObjekt.h"

class BBoxDecorator: public GraphObjekt{
public:
    BBoxDecorator(GraphObjekt *graphObject);
    BBoxDecorator(const BBoxDecorator&) = delete;
    BBoxDecorator& operator=(const BBoxDecorator&) = delete;
    ~BBoxDecorator();
    GraphObjekt *getGraphObj() const;
    void draw(QPainter &painter) override;
    void update(QPoint newPoint) override;
    bool hit(QPoint click) override;
    void moveTo(QPoint point) override;
    BBoxDecorator* copy() override;
    void calcBBox(QPoint &min, QPoint &max) override;
    bool isValid() override;
    bool isNoSizeObjekt() override;
    void setSelected(bool b) override;
    bool getSelected() override;
    void setColor(QColor color) override;
    bool getFilled() override;
    void setFilled(bool filled) override;
    void setBBox(bool newBBox);

private:
    GraphObjekt *graphObj;
    bool bBox;
};

#endif // BBOXDECORATOR_H
