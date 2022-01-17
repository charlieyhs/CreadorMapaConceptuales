#ifndef SQUAREGRAPHICSOBJECT_H
#define SQUAREGRAPHICSOBJECT_H

#include <QGraphicsObject>

class SquareGraphicsObject : public QGraphicsObject
{
    Q_OBJECT
public:
    SquareGraphicsObject(QGraphicsObject *parent = nullptr);
    void setPosition(const QPoint &position);
    void join(SquareGraphicsObject *other);

    void setText(const QString &text){
        mText = text;
    }
    void setSize(const QSize &size){
        mSize = size;
    }
    void setSelectedMark(bool selected){
        mSelectedMark = selected;
    }
    bool selectedMark()const{
        return mSelectedMark;
    }
    QSize getSize()const{
        return mSize;
    }
protected:
    QRectF boundingRect()const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget = nullptr);
private:
    QString mText;
    QPoint mPosition;
    QSize mSize;
    QList<SquareGraphicsObject *>mOthers;
    bool mSelectedMark;
};

#endif // SQUAREGRAPHICSOBJECT_H
