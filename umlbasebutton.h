#ifndef UMLBASEBUTTON_H
#define UMLBASEBUTTON_H

#include <QPushButton>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>

class UMLGraphicsScene;

class UMLBaseButton : public QPushButton
{
    Q_OBJECT
public:
    explicit UMLBaseButton(QWidget *parent = nullptr);
    virtual ~UMLBaseButton();

    virtual void sceneMousePressEvent(UMLGraphicsScene* scene, QGraphicsSceneMouseEvent *event);
    virtual void sceneMouseMoveEvent(UMLGraphicsScene* scene, QGraphicsSceneMouseEvent *event);
    virtual void sceneMouseReleaseEvent(UMLGraphicsScene* scene, QGraphicsSceneMouseEvent *event);
    virtual void sceneKeyPressEvent(UMLGraphicsScene* scene, QKeyEvent *event);

    virtual void clear(UMLGraphicsScene* scene) = 0;

signals:

};

#endif // UMLBASEBUTTON_H
