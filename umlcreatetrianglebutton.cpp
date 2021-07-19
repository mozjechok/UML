#include "umlcreatetrianglebutton.h"
#include "umlpolygon.h"

QPolygonF UMLCreateTriangleButton::equilateralTriangle = QPolygonF(
            QList<QPointF>({QPointF(0, 0), QPointF(1 / 2.0, sqrt(3) / 2), QPointF(1, 0)}));

QRectF UMLCreateTriangleButton::triangleBoundingRect = QRectF(0, 0, 1, sqrt(3) / 2);

UMLCreateTriangleButton::UMLCreateTriangleButton(QWidget *parent) : UMLCreateBaseFigureButton(parent)
{

}

UMLBaseFigure *UMLCreateTriangleButton::createNewItem()
{
    return new UMLPolygon(equilateralTriangle);
}

void UMLCreateTriangleButton::setRectToGraphicsItem(UMLBaseFigure *item, const QPointF& previousPoint, const QPointF& currectPoint)
{
    QPointF center = (previousPoint + currectPoint) / 2;
    QPointF size   = currectPoint - previousPoint;

    auto poligonItem = reinterpret_cast<UMLPolygon*>(item);

    QTransform transform;

    transform.translate(center.x(),
                        center.y());

    transform.scale(size.x() / triangleBoundingRect.width(),
                    size.y() / triangleBoundingRect.height());

    transform.translate(-triangleBoundingRect.center().x(),
                        -triangleBoundingRect.center().y());

    poligonItem->setPolygon(transform.map(equilateralTriangle));
}
