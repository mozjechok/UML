#include "umlcircle.h"

UMLCircle::UMLCircle(QGraphicsItem *parent)
    : UMLBaseFigure(parent), _rect()
{
}

UMLCircle::UMLCircle(const QRectF &rect, QGraphicsItem *parent)
    : UMLBaseFigure(parent), _rect(rect)
{

}

UMLCircle::~UMLCircle()
{
}

QRectF UMLCircle::rect() const
{
    return _rect;
}

void UMLCircle::setRect(const QRectF &rect)
{
    if (_rect == rect)
        return;
    prepareGeometryChange();
    _rect = rect;
    _boundingRect = QRectF();
    update();
}

QRectF UMLCircle::boundingRect() const
{
    if (_boundingRect.isNull()) {
        qreal halfpw = pen().style() == Qt::NoPen ? qreal(0) : pen().widthF() / 2;
        _boundingRect = _rect;
        if (halfpw > 0.0)
            _boundingRect.adjust(-halfpw, -halfpw, halfpw, halfpw);
    }
    return _boundingRect;
}

QPainterPath UMLCircle::shape() const
{
    QPainterPath path;
    if (_rect.isNull())
        return path;

    path.addEllipse(_rect);

    return qt_graphicsItem_shapeFromPath(path, _pen);
}

void UMLCircle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                                 QWidget *widget)
{
    painter->setPen(_pen);
    painter->setBrush(_brush);
    painter->drawEllipse(_rect);

    if (option->state & QStyle::State_Selected)
        qt_graphicsItem_highlightSelected(this, painter, option);
}

int UMLCircle::type() const
{
    return Type;
}
