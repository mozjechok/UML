#ifndef UMLCREATETRIANGLEBUTTON_H
#define UMLCREATETRIANGLEBUTTON_H

#include "umlcreatebasefigurebutton.h"

class UMLCreateTriangleButton : public UMLCreateBaseFigureButton
{
    Q_OBJECT
public:
    explicit UMLCreateTriangleButton(QWidget *parent = nullptr);

    UMLBaseFigure* createNewItem() override;
    void setRectToGraphicsItem(UMLBaseFigure* item, const QPointF& previousPoint, const QPointF& currectPoint) override;

private:
    static QPolygonF equilateralTriangle;
    static QRectF triangleBoundingRect;
};

#endif // UMLCREATETRIANGLEBUTTON_H
