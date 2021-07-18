#include "umlgraphicsscene.h"

UMLGraphicsScene::UMLGraphicsScene(QObject *parent) :
    QGraphicsScene(parent), currectButton(nullptr)
{

}

void UMLGraphicsScene::changeButton(UMLBaseButton *newButton)
{
    if(newButton == currectButton)
        return;

    if(currectButton != nullptr)
    {
        currectButton->clear(this);
        currectButton->setChecked(false);
    }
    currectButton = newButton;
}


void UMLGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(currectButton != nullptr)
    {
        currectButton->sceneMousePressEvent(this, event);

        if(!event->isAccepted())
        {
            event->accept();
            QGraphicsScene::mousePressEvent(event);
        }
    }
    else
        QGraphicsScene::mousePressEvent(event);
}

void UMLGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(currectButton != nullptr)
    {
        currectButton->sceneMouseMoveEvent(this, event);

        if(!event->isAccepted())
            QGraphicsScene::mouseMoveEvent(event);
    }
    else
        QGraphicsScene::mouseMoveEvent(event);
}

void UMLGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(currectButton != nullptr)
    {
        currectButton->sceneMouseReleaseEvent(this, event);

        if(!event->isAccepted())
            QGraphicsScene::mouseReleaseEvent(event);
    }
    else
        QGraphicsScene::mouseReleaseEvent(event);
}

void UMLGraphicsScene::keyPressEvent(QKeyEvent *event)
{
    if(currectButton != nullptr)
    {
        currectButton->sceneKeyPressEvent(this, event);

        if(!event->isAccepted())
            QGraphicsScene::keyPressEvent(event);
    }
    else
        QGraphicsScene::keyPressEvent(event);
}
