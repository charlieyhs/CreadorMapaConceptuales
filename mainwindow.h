#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class DocumentsGraphicsScene;

namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    enum Option{
        NEW_DOCUMENT,
        ADD_SQUARE,
        QUIT_APPLICATION
    };

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Q_INVOKABLE void executeOption(int option);
    Q_INVOKABLE QSize quickWidgetSize()const;

private:
    Ui::MainWindow *ui;
    DocumentsGraphicsScene *mScene;
};
#endif // MAINWINDOW_H
