#include "umlcreatebasefigurebutton.h"
#include "umlgraphicsscene.h"

UMLCreateBaseFigureButton::UMLCreateBaseFigureButton(QWidget *parent) :
    UMLBaseButton(parent), currentItem(nullptr), mouseLeftButton(false)
{

}

UMLCreateBaseFigureButton::~UMLCreateBaseFigureButton()
{

}

void UMLCreateBaseFigureButton::sceneMousePressEvent(UMLGraphicsScene *scene, QGraphicsSceneMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        mouseLeftButton = true;
        previousPosition = event->scenePos();

        currentItem = createNewItem();
        currentItem->setBrush(QBrush(QColor(255,255,255)));
        scene->addItem(qgraphicsitem_cast<QGraphicsItem*>(currentItem));
    }
    event->accept();
}

void UMLCreateBaseFigureButton::sceneMouseMoveEvent(UMLGraphicsScene *scene, QGraphicsSceneMouseEvent *event)
{
    if(mouseLeftButton)
    {
        setRectToGraphicsItem(currentItem, previousPosition, event->scenePos());
    }
    event->accept();
}

void UMLCreateBaseFigureButton::sceneMouseReleaseEvent(UMLGraphicsScene *scene, QGraphicsSceneMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        mouseLeftButton = false;
        currentItem = nullptr;
    }
    event->accept();
}

void UMLCreateBaseFigureButton::clear(UMLGraphicsScene* scene)
{
    if(currentItem != nullptr)
    {
        scene->removeItem(currentItem);
        delete currentItem;
        currentItem = nullptr;
    }
    mouseLeftButton = false;
}

QRectF twoPointsToRect(const QPointF &first, const QPointF &second)
{
    qreal buf;
    QPointF topLeft = first, bottomRight = second;

    if(topLeft.x() > bottomRight.x())
    {
        buf = topLeft.x();
        topLeft.setX(bottomRight.x());
        bottomRight.setX(buf);
    }

    if(topLeft.y() > bottomRight.y())
    {
        buf = topLeft.y();
        topLeft.setY(bottomRight.y());
        bottomRight.setY(buf);
    }

    return QRectF(topLeft, bottomRight);
}
