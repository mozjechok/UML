#ifndef UMLMOVEHANDBUTTON_H
#define UMLMOVEHANDBUTTON_H

#include "umlbasebutton.h"

class UMLMoveHandButton : public UMLBaseButton
{
    Q_OBJECT
public:
    explicit UMLMoveHandButton(QWidget *parent = nullptr);
    ~UMLMoveHandButton();

    void clear(UMLGraphicsScene* scene) override;

signals:

};

#endif // UMLMOVEHANDBUTTON_H
