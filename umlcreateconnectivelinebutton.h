#ifndef UMLCREATECONNECTIVELINEBUTTON_H
#define UMLCREATECONNECTIVELINEBUTTON_H

#include "umlbasebutton.h"
#include "umlconnectiveline.h"

class UMLCreateConnectiveLineButton : public UMLBaseButton
{
    Q_OBJECT
public:
    explicit UMLCreateConnectiveLineButton(QWidget *parent = nullptr);
    ~UMLCreateConnectiveLineButton();

    void sceneMousePressEvent(UMLGraphicsScene* scene, QGraphicsSceneMouseEvent *event) override;
    void sceneMouseMoveEvent(UMLGraphicsScene* scene, QGraphicsSceneMouseEvent *event) override;
    void sceneMouseReleaseEvent(UMLGraphicsScene* scene, QGraphicsSceneMouseEvent *event) override;

    void clear(UMLGraphicsScene* scene) override;

private:
    UMLBaseFigure* firstItem;

};

#endif // UMLCREATECONNECTIVELINEBUTTON_H
