#ifndef DOCUMENTSGRAPHICSSCENE_H
#define DOCUMENTSGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QObject>

class DocumentsGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit DocumentsGraphicsScene(QObject *parent = nullptr);
    void addSquare(const QString &text, const QPoint &position,
                   const QSize &size);
protected:
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
private:
    QGraphicsItem *mItemUnderMouse;
    QGraphicsItem *mSelectedItemByDoubleClick;
    QGraphicsItem *getItemUnderMouseUpdatinCurrentItem();
};

#endif // DOCUMENTSGRAPHICSSCENE_H
