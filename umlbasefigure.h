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

    enum CornerFlags {
        Top = 0x01,
        Bottom = 0x02,
        Left = 0x04,
        Right = 0x08,
        TopLeft = Top|Left,
        TopRight = Top|Right,
        BottomLeft = Bottom|Left,
        BottomRight = Bottom|Right
    };

    virtual QRectF rect() const = 0;
    virtual void setRect(const QRectF &rect) = 0;

    QPen pen() const;
    void setPen(const QPen &pen);

    QBrush brush() const;
    void setBrush(const QBrush &brush);

    bool isObscuredBy(const QGraphicsItem *item) const override;
    QPainterPath opaqueArea() const override;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event) override;
    void hoverMoveEvent(QGraphicsSceneHoverEvent *event) override;

signals:
    void signalMove(QGraphicsItem *item);

protected:
    QBrush _brush;
    QPen _pen;

    mutable QRectF _boundingRect;

private:
    const int resizeArea = 8;
    const int resizeLimit = 10;
    unsigned short int cornerFlags;
    bool mouseLeftButton = false;
    QPointF previousPosition;


    void resizeLeft( const QPointF &pt);
    void resizeRight( const QPointF &pt);
    void resizeBottom(const QPointF &pt);
    void resizeTop(const QPointF &pt);


};

#endif // UMLBASEFIGURE_H
