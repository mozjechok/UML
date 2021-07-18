#include "umlcreaterectanglebutton.h"
#include "umlrectangle.h"

UMLCreateRectangleButton::UMLCreateRectangleButton(QWidget *parent) : UMLCreateBaseFigureButton(parent)
{

}

UMLBaseFigure *UMLCreateRectangleButton::createNewItem()
{
    return new UMLRectangle();
}

void UMLCreateRectangleButton::setRectToGraphicsItem(UMLBaseFigure *item, const QPointF& previousPoint, const QPointF& currectPoint)
{
    reinterpret_cast<UMLRectangle*>(item)->setRect(
                twoPointsToRect(previousPoint, currectPoint));
}
