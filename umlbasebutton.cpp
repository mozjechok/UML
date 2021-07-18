#include "umlbasebutton.h"

UMLBaseButton::UMLBaseButton(QWidget *parent) : QPushButton(parent)
{

}

UMLBaseButton::~UMLBaseButton()
{
}

void UMLBaseButton::sceneMousePressEvent(UMLGraphicsScene *scene, QGraphicsSceneMouseEvent *event)
{
    event->ignore();
}

void UMLBaseButton::sceneMouseMoveEvent(UMLGraphicsScene *scene, QGraphicsSceneMouseEvent *event)
{
    event->ignore();
}

void UMLBaseButton::sceneMouseReleaseEvent(UMLGraphicsScene *scene, QGraphicsSceneMouseEvent *event)
{
    event->ignore();
}

void UMLBaseButton::sceneKeyPressEvent(UMLGraphicsScene *scene, QKeyEvent *event)
{
    event->ignore();
}
