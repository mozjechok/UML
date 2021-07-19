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
    setAcceptHoverEvents(true);
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
    auto pt = event->pos();

    if(mouseLeftButton)
    {
        switch (cornerFlags) {
        case Top:
            resizeTop(pt);
            break;
        case Bottom:
            resizeBottom(pt);
            break;
        case Left:
            resizeLeft(pt);
            break;
        case Right:
            resizeRight(pt);
            break;
        case TopLeft:
            resizeTop(pt);
            resizeLeft(pt);
            break;
        case TopRight:
            resizeTop(pt);
            resizeRight(pt);
            break;
        case BottomLeft:
            resizeBottom(pt);
            resizeLeft(pt);
            break;
        case BottomRight:
            resizeBottom(pt);
            resizeRight(pt);
            break;
        default:
            {
                moveBy(event->scenePos().x() - previousPosition.x(),
                       event->scenePos().y() - previousPosition.y());
                previousPosition = event->scenePos();
            }
            break;
        }
    }

    emit signalMove(this);
}

void UMLBaseFigure::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() & Qt::LeftButton)
    {
        mouseLeftButton = false;
    }
}

void UMLBaseFigure::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setSelected(true);
    QGraphicsItem::hoverEnterEvent(event);
}

void UMLBaseFigure::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setSelected(false);
    setCursor(QCursor());
    QGraphicsItem::hoverLeaveEvent(event);
}

void UMLBaseFigure::hoverMoveEvent(QGraphicsSceneHoverEvent *event)
{
    qreal drx = event->pos().x() - rect().right();
    qreal dlx = event->pos().x() - rect().left();

    qreal dby = event->pos().y() - rect().bottom();
    qreal dty = event->pos().y() - rect().top();


    cornerFlags = 0;
    if( abs(dty) < resizeArea ) cornerFlags |= Top;
    if( abs(dby) < resizeArea ) cornerFlags |= Bottom;
    if( abs(drx) < resizeArea ) cornerFlags |= Right;
    if( abs(dlx) < resizeArea ) cornerFlags |= Left;

    switch (cornerFlags) {
    case Top:
    case Bottom:
        setCursor(Qt::SizeVerCursor);
        break;
    case Left:
    case Right:
        setCursor(Qt::SizeHorCursor);
        break;
    case TopRight:
    case BottomLeft:
        setCursor(Qt::SizeBDiagCursor);
        break;
    case TopLeft:
    case BottomRight:
        setCursor(Qt::SizeFDiagCursor);
        break;
    default:
        setCursor(QCursor());
        break;
    }

    QGraphicsItem::hoverMoveEvent( event );
}


void UMLBaseFigure::resizeLeft(const QPointF &pt)
{
    QRectF tmpRect = rect();
    if(pt.x() > tmpRect.right())
        return;

    qreal width = abs( pt.x() - tmpRect.right() );
    if(width < resizeLimit)
        return;

    tmpRect.setWidth(width);
    tmpRect.translate(rect().width() - tmpRect.width(), 0); //when rect was resized it translated in right side, fix this

    prepareGeometryChange();
    setRect(tmpRect);
    update();
}

void UMLBaseFigure::resizeRight(const QPointF &pt)
{
    QRectF tmpRect = rect();
    if(pt.x() < tmpRect.left())
        return;

    qreal width = abs( pt.x() - tmpRect.left() );
    if(width < resizeLimit)
        return;

    tmpRect.setWidth(width);

    prepareGeometryChange();
    setRect(tmpRect);
    update();
}

//top in qt is a botton part of the screen, so swap top and botton
void UMLBaseFigure::resizeBottom(const QPointF &pt)
{
    QRectF tmpRect = rect();
    if(pt.y() < tmpRect.top())
        return;

    qreal height = abs( pt.y() - tmpRect.top() );
    if( height < resizeLimit )
        return;

    tmpRect.setHeight(height);

    prepareGeometryChange();
    setRect(tmpRect);
    update();
}

void UMLBaseFigure::resizeTop(const QPointF &pt)
{
    QRectF tmpRect = rect();
    if(pt.y() > tmpRect.bottom())
        return;

    qreal height = abs( pt.y() - tmpRect.bottom() );
    if( height < resizeLimit )
        return;

    tmpRect.setHeight(height);
    tmpRect.translate(0, rect().height() - tmpRect.height()); //when rect was resized it translated in top side, fix this

    prepareGeometryChange();
    setRect(tmpRect);
    update();
}
