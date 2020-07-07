#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->imageImportBut, SIGNAL(clicked(bool)), this, SLOT(openImage()));
//    connect(ui->recttangleBut, SIGNAL(clicked(bool)), this, SLOT());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImage(){
    QString openFile;

    openFile = QFileDialog::getOpenFileName(this, tr("open image"), "",
                                            "Image File(*.png *.jpg *.bmp);;Text(*.txt)");
    if(openFile != ""){
        if(image.load(openFile))
            ui->photoFrame->setPixmap(QPixmap::fromImage(image).scaled(ui->photoFrame->size()));
    }
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    QPen pen(QColor(255, 0, 0));
    QBrush brush(QColor(0, 255, 0, 0));

    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(50, 100, 700, 450);
}


