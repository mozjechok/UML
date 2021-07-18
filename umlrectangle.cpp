#include "umlrectangle.h"


UMLRectangle::UMLRectangle(QGraphicsItem *parent)
    : UMLBaseFigure(parent)
{
}

UMLRectangle::UMLRectangle(const QRectF &rect, QGraphicsItem *parent)
    : UMLBaseFigure(parent), _rect(rect)
{
}

UMLRectangle::~UMLRectangle()
{
}

QRectF UMLRectangle::rect() const
{
    return _rect;
}

void UMLRectangle::setRect(const QRectF &rect)
{
    if (_rect == rect)
        return;
    prepareGeometryChange();
    _rect = rect;
    _boundingRect = QRectF();
    update();
}

QRectF UMLRectangle::boundingRect() const
{
    if (_boundingRect.isNull()) {
        qreal halfpw = pen().style() == Qt::NoPen ? qreal(0) : pen().widthF() / 2;
        _boundingRect = _rect;
        if (halfpw > 0.0)
            _boundingRect.adjust(-halfpw, -halfpw, halfpw, halfpw);
    }
    return _boundingRect;
}

QPainterPath UMLRectangle::shape() const
{
    QPainterPath path;
    path.addRect(_rect);
    return qt_graphicsItem_shapeFromPath(path, _pen);
}

void UMLRectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                              QWidget *widget)
{
    painter->setPen(_pen);
    painter->setBrush(_brush);
    painter->drawRect(_rect);

    if (option->state & QStyle::State_Selected)
        qt_graphicsItem_highlightSelected(this, painter, option);
}


int UMLRectangle::type() const
{
    return Type;
}
