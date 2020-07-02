#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QLineEdit>
#include <QImage>
#include <QFileInfo>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(openImage()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImage(){
    QString openFile, openFilePath;
    QImage image;

    openFile = QFileDialog::getOpenFileName(this,tr("open image"),"",
                                            "Image Files(*.png *.jpg *.bmp)");
    if(openFile != ""){
        if(image.load(openFile))
            ui->label->setPixmap(QPixmap::fromImage(image).scaled(ui->label->size()));
    }
    QFileInfo openFileInfo;
    openFileInfo = QFileInfo(openFile);
    openFilePath = openFileInfo.filePath();
    ui->lineEdit->setText(openFilePath);
}
