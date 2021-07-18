#include "umlpolygon.h"

UMLPolygon::UMLPolygon(const QPolygonF &polygon, QGraphicsItem *parent)
    : UMLBaseFigure(parent), _polygon(polygon), _fillRule(Qt::OddEvenFill)
{
}

UMLPolygon::UMLPolygon(QGraphicsItem *parent)
    : UMLBaseFigure(parent), _polygon(), _fillRule(Qt::OddEvenFill)
{
}


UMLPolygon::~UMLPolygon()
{
}

QRectF UMLPolygon::rect() const
{
    return boundingRect();
}

void UMLPolygon::setRect(const QRectF &rect)
{
    QTransform transform;
    transform.translate(rect.center().x() - boundingRect().center().x(),
                        rect.center().y() - boundingRect().center().y());

    transform.scale(rect.width() / boundingRect().width(),
                    rect.height() / boundingRect().height());

    transform.translate(-boundingRect().center().x(),
                        -boundingRect().center().y());

    setPolygon(transform.map(polygon()));
}


QPolygonF UMLPolygon::polygon() const
{
    return _polygon;
}


void UMLPolygon::setPolygon(const QPolygonF &polygon)
{
    if (_polygon == polygon)
        return;
    prepareGeometryChange();
    _polygon = polygon;
    _boundingRect = QRectF();
    update();
}

Qt::FillRule UMLPolygon::fillRule() const
{
     return _fillRule;
}

void UMLPolygon::setFillRule(Qt::FillRule rule)
{
     if (rule != _fillRule) {
         _fillRule = rule;
         update();
     }
}

QRectF UMLPolygon::boundingRect() const
{
    if (_boundingRect.isNull()) {
        qreal pw = pen().style() == Qt::NoPen ? qreal(0) : pen().widthF();
        if (pw == 0.0)
            _boundingRect = _polygon.boundingRect();
        else
            _boundingRect = shape().controlPointRect();
    }
    return _boundingRect;
}

QPainterPath UMLPolygon::shape() const
{
    QPainterPath path;
    path.addPolygon(_polygon);
    return qt_graphicsItem_shapeFromPath(path, _pen);
}

void UMLPolygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(_pen);
    painter->setBrush(_brush);
    painter->drawPolygon(_polygon, _fillRule);

    if (option->state & QStyle::State_Selected)
        qt_graphicsItem_highlightSelected(this, painter, option);
}

int UMLPolygon::type() const
{
    return Type;
}
