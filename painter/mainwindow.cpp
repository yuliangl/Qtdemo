#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPen pen;
    pen.setColor(QColor(255, 0, 0));
    QBrush brush(QColor(0, 255, 0, 0));
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(100, 100, 800, 600);
}
