#ifndef UMLRECTANGLE_H
#define UMLRECTANGLE_H

#include "umlbasefigure.h"

class UMLRectangle : public UMLBaseFigure
{
    Q_OBJECT
public:
    explicit UMLRectangle(QGraphicsItem *parent = nullptr);
    explicit UMLRectangle(const QRectF &rect, QGraphicsItem *parent = nullptr);
    ~UMLRectangle();

    QRectF rect() const override;
    void setRect(const QRectF &rect) override;

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    enum { Type = 11 };
    int type() const override;

protected:
    QRectF _rect;

};

#endif // UMLRECTANGLE_H
