#ifndef UMLTRIANGLE_H
#define UMLTRIANGLE_H

#include "umlbasefigure.h"

class UMLPolygon : public UMLBaseFigure
{
    Q_OBJECT
public:
    explicit UMLPolygon(QGraphicsItem *parent = nullptr);
    explicit UMLPolygon(const QPolygonF &polygon, QGraphicsItem *parent = nullptr);
    ~UMLPolygon();

    QRectF rect() const override;
    void setRect(const QRectF &rect) override;

    QPolygonF polygon() const;
    void setPolygon(const QPolygonF &polygon);

    Qt::FillRule fillRule() const;
    void setFillRule(Qt::FillRule rule);

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    enum { Type = 13 };
    int type() const override;

protected:
    QPolygonF _polygon;
    Qt::FillRule _fillRule;

};

#endif // UMLTRIANGLE_H
