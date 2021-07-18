#ifndef UMLCREATERECTANGLEBUTTON_H
#define UMLCREATERECTANGLEBUTTON_H

#include "umlcreatebasefigurebutton.h"

class UMLCreateRectangleButton : public UMLCreateBaseFigureButton
{
    Q_OBJECT
public:
    explicit UMLCreateRectangleButton(QWidget *parent = nullptr);

    UMLBaseFigure* createNewItem() override;
    void setRectToGraphicsItem(UMLBaseFigure* item, const QPointF& previousPoint, const QPointF& currectPoint) override;
};

#endif // UMLCREATERECTANGLEBUTTON_H
