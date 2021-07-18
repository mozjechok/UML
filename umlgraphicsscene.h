#ifndef UMLGRAPHICSSCENE_H
#define UMLGRAPHICSSCENE_H

#include "umlbasebutton.h"
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QGraphicsItem>

class UMLGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit UMLGraphicsScene(QObject *parent = nullptr);

    void changeButton(UMLBaseButton* newButton);

signals:


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    UMLBaseButton* currectButton;
};

#endif // UMLGRAPHICSSCENE_H
