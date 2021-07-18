#include "umlconnectiveline.h"
#include <QGraphicsScene>
#include <QGraphicsView>

UMLConnectiveLine::UMLConnectiveLine(QObject *parent) :
    QObject(parent)
{

}

UMLConnectiveLine::UMLConnectiveLine(UMLBaseFigure *firstItem, UMLBaseFigure *secondItem, QObject *parent) :
    QObject(parent)
{
    setFirstItem(firstItem);
    setSecondItem(secondItem);
}

void UMLConnectiveLine::updatePath()
{
    QPainterPath newPath;

    if(firstItem != nullptr)
        newPath.moveTo(firstItem ->mapToScene(firstItem ->boundingRect().center()));
    else
        newPath.moveTo(0,0);

    if(secondItem != nullptr)
        newPath.lineTo(secondItem->mapToScene(secondItem->boundingRect().center()));
    else
        newPath.lineTo(0,0);

    setPath(newPath);
    update();
}

void UMLConnectiveLine::setFirstItem(UMLBaseFigure *item)
{
    if(firstItem == item)
        return;

    if(firstItem != nullptr)
        disconnect(firstItem, &UMLBaseFigure::signalMove, this, &UMLConnectiveLine::firstItemMoveSlot);

    firstItem = item;
    if(firstItem != nullptr)
        connect(firstItem, &UMLBaseFigure::signalMove, this, &UMLConnectiveLine::firstItemMoveSlot);

    updatePath();
}

void UMLConnectiveLine::setSecondItem(UMLBaseFigure *item)
{
    if(secondItem == item)
        return;
    if(secondItem != nullptr)
        disconnect(secondItem, &UMLBaseFigure::signalMove, this, &UMLConnectiveLine::firstItemMoveSlot);

    secondItem = item;
    if(secondItem != nullptr)
        connect(secondItem, &UMLBaseFigure::signalMove, this, &UMLConnectiveLine::firstItemMoveSlot);

    updatePath();
}

UMLBaseFigure *UMLConnectiveLine::getFirstItem() const
{
    return firstItem;
}

UMLBaseFigure *UMLConnectiveLine::getSecondItem() const
{
    return secondItem;
}

void UMLConnectiveLine::firstItemMoveSlot(QGraphicsItem *item)
{
    updatePath();
}

void UMLConnectiveLine::secondItemMoveSlot(QGraphicsItem *item)
{
    updatePath();
}
