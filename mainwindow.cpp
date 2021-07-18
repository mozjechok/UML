#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new UMLGraphicsScene(this);
    scene->setSceneRect(0,0,2000,2000);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    ui->graphicsView->setCursor(QCursor());
    connect(ui->triangleButton, &QPushButton::clicked, [=](){scene->changeButton(ui->triangleButton);});
    connect(ui->circleButton, &QPushButton::clicked, [=](){scene->changeButton(ui->circleButton);});
    connect(ui->rectangleButton, &QPushButton::clicked, [=](){scene->changeButton(ui->rectangleButton);});
    connect(ui->lineButton, &QPushButton::clicked, [=](){scene->changeButton(ui->lineButton);});
    connect(ui->handButton, &QPushButton::clicked, [=](){scene->changeButton(ui->handButton);});
}

MainWindow::~MainWindow()
{
    delete ui;
}

