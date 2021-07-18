#ifndef UMLBASEFIGURE_H
#define UMLBASEFIGURE_H

#include <QBrush>
#include <QPen>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QPainter>
#include <QDebug>
#include <QCursor>
#include <QStyleOptionGraphicsItem>


QPainterPath qt_graphicsItem_shapeFromPath(const QPainterPath &path, const QPen &pen);

//qt function to highlight selected items
void Q_WIDGETS_EXPORT qt_graphicsItem_highlightSelected(
    QGraphicsItem *item, QPainter *painter, const QStyleOptionGraphicsItem *option);

class UMLBaseFigure : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit UMLBaseFigure(QGraphicsItem *parent = nullptr);
    ~UMLBaseFigure();

    virtual QRectF rect() const = 0;
    virtual void setRect(const QRectF &rect) = 0;

    QPen pen() const;
    void setPen(const QPen &pen);

    QBrush brush() const;
    void setBrush(const QBrush &brush);

    bool isObscuredBy(const QGraphicsItem *item) const override;
    QPainterPath opaqueArea() const override;

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

signals:
    void signalMove(QGraphicsItem *item);

protected:
    QBrush _brush;
    QPen _pen;

    mutable QRectF _boundingRect;

    bool mouseLeftButton = false;
    QPointF previousPosition;
};

#endif // UMLBASEFIGURE_H
