#include "squaregraphicsobject.h"
#include <QPainter>

SquareGraphicsObject::SquareGraphicsObject(QGraphicsObject *parent)
    : QGraphicsObject(parent)
{
    mSelectedMark = false;
}

void SquareGraphicsObject::setPosition(const QPoint &position){
    mPosition.setX(position.x() - mSize.width()/2);
    mPosition.setY(position.y() - mSize.height()/2);
}
void SquareGraphicsObject::join(SquareGraphicsObject *other){
    if(this == other){
        // no se hace nada
    }else{
        //Conectamos con una linea
        if(mOthers.contains(other)){
            //No hacemos nada
        }else{
            mOthers.append(other);
        }
    }
}
QRectF SquareGraphicsObject::boundingRect() const{
    return QRectF(mPosition.x(), mPosition.y(), mSize.width(),mSize.height());
}

void SquareGraphicsObject::paint(QPainter *painter,
                                 const QStyleOptionGraphicsItem *option,
                                 QWidget *widget){
    if(mSelectedMark){
    //Dibujamos un cuadro relleno de color amarillo
        painter->fillRect(boundingRect(),Qt::yellow);
        painter->drawRect(boundingRect());
    }else{
        //rectangulo normal
        painter->drawRect(boundingRect());
    }
    //Dibujamos el texto
    painter->drawText(mPosition.x(),mPosition.y(),mSize.width(),mSize.height(), Qt::TextWordWrap,mText);
    //pintamos las lineas que conectan con otros cuadros
    const int nOtros = mOthers.size();
    for(int ax = 0; ax<nOtros;ax++){
        painter->drawLine(mPosition.x()+mSize.width()/2,
                          mPosition.y()+mSize.height(),
                          mOthers[ax]->mPosition.x()+ mOthers[ax]->mSize.width(),
                          mOthers[ax]->mPosition.y());
    }
    (void)option;
    (void)widget;
}
