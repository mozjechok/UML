#include "umlbasefigure.h"
#include <QGraphicsScene>

QPainterPath qt_graphicsItem_shapeFromPath(const QPainterPath &path, const QPen &pen)
{
    // We unfortunately need this hack as QPainterPathStroker will set a width of 1.0
    // if we pass a value of 0.0 to QPainterPathStroker::setWidth()
    const qreal penWidthZero = qreal(0.00000001);

    if (path == QPainterPath() || pen == Qt::NoPen)
        return path;
    QPainterPathStroker ps;
    ps.setCapStyle(pen.capStyle());
    if (pen.widthF() <= 0.0)
        ps.setWidth(penWidthZero);
    else
        ps.setWidth(pen.widthF());
    ps.setJoinStyle(pen.joinStyle());
    ps.setMiterLimit(pen.miterLimit());
    QPainterPath p = ps.createStroke(path);
    p.addPath(path);
    return p;
}

UMLBaseFigure::UMLBaseFigure(QGraphicsItem *parent)
    : QObject(), QGraphicsItem(parent)
{
    setFlags(ItemIsSelectable|ItemSendsGeometryChanges);
}

UMLBaseFigure::~UMLBaseFigure()
{
}

QPen UMLBaseFigure::pen() const
{
    return _pen;
}

void UMLBaseFigure::setPen(const QPen &pen)
{
    if (_pen == pen)
        return;
    prepareGeometryChange();
    _pen = pen;
    _boundingRect = QRectF();
    update();
}

QBrush UMLBaseFigure::brush() const
{
    return _brush;
}

void UMLBaseFigure::setBrush(const QBrush &brush)
{
    if (_brush == brush)
        return;
    _brush = brush;
    update();
}

bool UMLBaseFigure::isObscuredBy(const QGraphicsItem *item) const
{
    return QGraphicsItem::isObscuredBy(item);
}

QPainterPath UMLBaseFigure::opaqueArea() const
{
    if (_brush.isOpaque())
        return isClipped() ? clipPath() : shape();
    return QGraphicsItem::opaqueArea();
}

void UMLBaseFigure::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        mouseLeftButton = true;
        previousPosition = event->scenePos();
    }
    event->accept();
}

void UMLBaseFigure::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(mouseLeftButton)
    {
        auto dx = event->scenePos().x() - previousPosition.x();
        auto dy = event->scenePos().y() - previousPosition.y();
        moveBy(dx,dy);
        update();
        previousPosition = event->scenePos();
        emit signalMove(this);
    }
}

void UMLBaseFigure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        mouseLeftButton = false;
    }
}
