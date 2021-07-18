#ifndef UMLCREATECIRCLEBUTTON_H
#define UMLCREATECIRCLEBUTTON_H

#include "umlcreatebasefigurebutton.h"

class UMLCreateCircleButton : public UMLCreateBaseFigureButton
{
    Q_OBJECT
public:
    explicit UMLCreateCircleButton(QWidget *parent = nullptr);

    UMLBaseFigure* createNewItem() override;
    void setRectToGraphicsItem(UMLBaseFigure* item, const QPointF& previousPoint, const QPointF& currectPoint) override;
};

#endif // UMLCREATECIRCLEBUTTON_H
