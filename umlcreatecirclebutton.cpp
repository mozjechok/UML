#include "umlcreatecirclebutton.h"
#include "umlcircle.h"

UMLCreateCircleButton::UMLCreateCircleButton(QWidget *parent) : UMLCreateBaseFigureButton(parent)
{

}

UMLBaseFigure *UMLCreateCircleButton::createNewItem()
{
    return new UMLCircle();
}

void UMLCreateCircleButton::setRectToGraphicsItem(UMLBaseFigure *item, const QPointF& previousPoint, const QPointF& currectPoint)
{
    reinterpret_cast<UMLCircle*>(item)->setRect(
                twoPointsToRect(previousPoint, currectPoint));
}
