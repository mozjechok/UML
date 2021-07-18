#ifndef UMLCONNECTIVELINE_H
#define UMLCONNECTIVELINE_H

#include "umlbasefigure.h"

class UMLConnectiveLine : public QObject, public QGraphicsPathItem
{
    Q_OBJECT
public:
    explicit UMLConnectiveLine(QObject *parent = nullptr);
    explicit UMLConnectiveLine(UMLBaseFigure *firstItem, UMLBaseFigure *secondSItem, QObject *parent = nullptr);

    void updatePath();

    void setFirstItem(UMLBaseFigure *item);
    void setSecondItem(UMLBaseFigure *item);

    UMLBaseFigure *getFirstItem() const;
    UMLBaseFigure *getSecondItem() const;

public slots:
    void firstItemMoveSlot(QGraphicsItem *item);
    void secondItemMoveSlot(QGraphicsItem *item);

private:
    UMLBaseFigure *firstItem  = nullptr;
    UMLBaseFigure *secondItem = nullptr;

};

#endif // UMLCONNECTIVELINE_H
