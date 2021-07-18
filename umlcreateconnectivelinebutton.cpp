#include "umlcreateconnectivelinebutton.h"
#include "umlgraphicsscene.h"

UMLCreateConnectiveLineButton::UMLCreateConnectiveLineButton(QWidget *parent) :
    UMLBaseButton(parent), firstItem(nullptr)
{

}

UMLCreateConnectiveLineButton::~UMLCreateConnectiveLineButton()
{

}

void UMLCreateConnectiveLineButton::sceneMousePressEvent(UMLGraphicsScene *scene, QGraphicsSceneMouseEvent *event)
{
    if(firstItem == nullptr)
    {
        auto item = qgraphicsitem_cast<UMLBaseFigure*>(
                    scene->itemAt(event->scenePos(), QTransform()));
        if(item != nullptr)
        {
            firstItem = item;
            firstItem->setSelected(true);
        }
    }
    else
    {
        auto item = qgraphicsitem_cast<UMLBaseFigure*>(
                    scene->itemAt(event->scenePos(), QTransform()));

        if(item != nullptr && item != firstItem)
        {
            firstItem->setSelected(false);

            auto line = new UMLConnectiveLine(firstItem, item);
            scene->addItem(qgraphicsitem_cast<QGraphicsItem*>(line));
            firstItem = nullptr;
        }
    }
    event->accept();
}

void UMLCreateConnectiveLineButton::sceneMouseMoveEvent(UMLGraphicsScene *scene, QGraphicsSceneMouseEvent *event)
{
    event->accept();
}

void UMLCreateConnectiveLineButton::sceneMouseReleaseEvent(UMLGraphicsScene *scene, QGraphicsSceneMouseEvent *event)
{
    event->accept();
}

void UMLCreateConnectiveLineButton::clear(UMLGraphicsScene *scene)
{
    if(firstItem != nullptr)
    {
        firstItem->setSelected(false);
        firstItem = nullptr;
    }
}
