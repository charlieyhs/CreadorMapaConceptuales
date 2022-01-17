#include "documentsgraphicsscene.h"
#include <QGraphicsSceneMouseEvent>
#include "squaregraphicsobject.h"

DocumentsGraphicsScene::DocumentsGraphicsScene(QObject *parent)
    : QGraphicsScene(0.0,0.0,600.0,600.0,parent)
{
    mItemUnderMouse = nullptr;
    mSelectedItemByDoubleClick = nullptr;

}

void DocumentsGraphicsScene::addSquare(const QString &text, const QPoint &position, const QSize &size)
{
    SquareGraphicsObject *square = new SquareGraphicsObject;
    square->setText(text);
    square->setPosition(position);
    square->setSize(size);
    addItem(square);
    update();
}

void DocumentsGraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *e)
{
    if(mSelectedItemByDoubleClick){
        // obtenemos el segundo elemento seleccionado
        SquareGraphicsObject *cuadro1 = nullptr;
        SquareGraphicsObject *cuadro2 = nullptr;
        QGraphicsItem *firstSelectedItem = nullptr;
        QGraphicsItem *secondSelectedItem = nullptr;

        firstSelectedItem = mSelectedItemByDoubleClick;
        secondSelectedItem = getItemUnderMouseUpdatinCurrentItem();

        if(secondSelectedItem){
            cuadro1 = static_cast<SquareGraphicsObject *>(firstSelectedItem);
            cuadro2 = static_cast<SquareGraphicsObject *>(secondSelectedItem);
            cuadro1->join(cuadro2);
            mSelectedItemByDoubleClick = nullptr;
        }
    }else{
        mSelectedItemByDoubleClick = getItemUnderMouseUpdatinCurrentItem();
    }
    e->accept();
}

void DocumentsGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    if(mItemUnderMouse){
        SquareGraphicsObject *cuadroItem = nullptr;
        cuadroItem = static_cast<SquareGraphicsObject *>(mItemUnderMouse);
        cuadroItem->setPosition(e->scenePos().toPoint());
        update();
    }
    e->accept();
}

void DocumentsGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    getItemUnderMouseUpdatinCurrentItem();
    e->accept();
}

void DocumentsGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    mItemUnderMouse = nullptr;
    e->accept();
}

QGraphicsItem *DocumentsGraphicsScene::getItemUnderMouseUpdatinCurrentItem()
{
    // Obtenemos el elementos actual (seleccionado)
    QList <QGraphicsItem *> objects = items();
    QGraphicsItem *itemUnderMouse = nullptr;
    SquareGraphicsObject *axItem = nullptr;
    const int nObjects = objects.size();
    for(int ax =0; ax < nObjects; ax++){
        //desmarcamos los objetos
        axItem = static_cast<SquareGraphicsObject *>(objects[ax]);
        axItem->setSelectedMark(false);
        if(objects[ax]->isUnderMouse()){
            itemUnderMouse = objects[ax];
        }
    }
    // Actualizamos el elementos actual
    mItemUnderMouse = itemUnderMouse;
    if(mItemUnderMouse){
        SquareGraphicsObject *square = nullptr;
        square = static_cast<SquareGraphicsObject *>(mItemUnderMouse);
        square->setSelectedMark(true);
    }
    update();
    return itemUnderMouse;
}
