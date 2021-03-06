#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "documentsgraphicsscene.h"
#include "addsquaredialog.h"

#include <QQmlContext>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mScene = new DocumentsGraphicsScene(this);
    ui->graphicsView->setScene(mScene);

    ui->quickWidget->resize(200, ui->quickWidget->size().height());
    ui->quickWidget->rootContext()->setContextProperty("mainwindow",this);
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/options.qml")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::executeOption(int option){
    switch(option){
    case NEW_DOCUMENT:{
        //crea documento nuevo
        delete mScene;
        mScene = new DocumentsGraphicsScene(this);
        ui->graphicsView->setScene(mScene);
        break;
    }
    case ADD_SQUARE:{
        // Agregar cuadro nuevo
        AddSquareDialog d(this);
        if(d.exec() == QDialog::Rejected){
            return;
        }
        QString text = d.squareText();
        QPoint position(100,100);
        QSize size = d.squareSize();
        mScene->addSquare(text,position,size);
        break;
    }
    case QUIT_APPLICATION:{
        qApp->quit();
        break;
    }
    }
}
QSize MainWindow::quickWidgetSize() const{
    return ui->quickWidget->size();
}

