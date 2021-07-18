#ifndef UMLCIRCLE_H
#define UMLCIRCLE_H

#include "umlbasefigure.h"

class UMLCircle : public UMLBaseFigure
{
    Q_OBJECT
public:
    explicit UMLCircle(QGraphicsItem *parent = nullptr);
    explicit UMLCircle(const QRectF &rect, QGraphicsItem *parent = nullptr);
    ~UMLCircle();

    QRectF rect() const override;
    void setRect(const QRectF &rect) override;

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    enum { Type = 12 };
    int type() const override;

protected:

    QRectF _rect;

};

#endif // UMLCIRCLE_H
