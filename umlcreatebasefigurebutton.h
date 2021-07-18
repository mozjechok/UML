#ifndef UMLCREATEBASEFIGUREBUTTON_H
#define UMLCREATEBASEFIGUREBUTTON_H

#include "umlbasebutton.h"
#include "umlbasefigure.h"

QRectF twoPointsToRect(const QPointF& first, const QPointF& second);

class UMLCreateBaseFigureButton : public UMLBaseButton
{
    Q_OBJECT
public:
    explicit UMLCreateBaseFigureButton(QWidget *parent = nullptr);
    ~UMLCreateBaseFigureButton();

    void sceneMousePressEvent(UMLGraphicsScene* scene, QGraphicsSceneMouseEvent *event) override;
    void sceneMouseMoveEvent(UMLGraphicsScene* scene, QGraphicsSceneMouseEvent *event) override;
    void sceneMouseReleaseEvent(UMLGraphicsScene* scene, QGraphicsSceneMouseEvent *event) override;

    void clear(UMLGraphicsScene* scene) override;

    virtual UMLBaseFigure* createNewItem() = 0;
    virtual void setRectToGraphicsItem(UMLBaseFigure* item, const QPointF& previousPoint, const QPointF& currectPoint) = 0;
signals:

private:
    UMLBaseFigure* currentItem;
    bool mouseLeftButton;
    QPointF previousPosition;
};

#endif // UMLCREATEBASEFIGUREBUTTON_H
