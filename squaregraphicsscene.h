#ifndef SQUAREGRAPHICSSCENE_H
#define SQUAREGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QObject>

class SquareGraphicsObject;

class SquareGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit SquareGraphicsScene(QObject *parent = nullptr);
    void updateWidth(int width);
    void updateHeight(int height);
    void updateText(const QString &text);

private:
    SquareGraphicsObject *mSquare;
};

#endif // SQUAREGRAPHICSSCENE_H
