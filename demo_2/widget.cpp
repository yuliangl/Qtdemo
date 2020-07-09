#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    label_img = new myLabel(this);
    connect(label_img, SIGNAL(startPointSignal(QPoint)),
            this, SLOT(startPointSlot(QPoint)));
    connect(label_img, SIGNAL(stopPointSignal(QPoint)),
            this, SLOT(stopPointSlot(QPoint)));
    label_img->setStyleSheet("border:1px solid rgb(0, 0, 0)");
    label_img->setMaximumSize(600, 350);
    label_img->setMinimumSize(600, 350);

    ui->label_layout->addWidget(label_img);

    connect(ui->pathBut, SIGNAL(clicked(bool)),
            this, SLOT(openPathSlot()));
    connect(ui->lineEdit_start_x, SIGNAL(textChanged(QString)),
            this, SLOT(pointTextChangeSlot(QString)));
    connect(ui->lineEdit_start_y, SIGNAL(textChanged(QString)),
            this, SLOT(pointTextChangeSlot(QString)));
    connect(ui->lineEdit_size_w, SIGNAL(textChanged(QString)),
            this, SLOT(pointTextChangeSlot(QString)));
    connect(ui->lineEdit_size_h, SIGNAL(textChanged(QString)),
            this, SLOT(pointTextChangeSlot(QString)));

}

void Widget::pointTextChangeSlot(QString){
    if(capture != NULL){
        double Start_x = ui->lineEdit_start_x->text().toInt();
        double Start_y = ui->lineEdit_start_y->text().toInt();
        double ROI_w = ui->lineEdit_size_w->text().toInt();
        double ROI_h = ui->lineEdit_size_h->text().toInt();
        double label_size_w = label_img->size().width();
        double label_size_h = label_img->size().height();
        double img_w = capture->get(3);
        double img_h = capture->get(4);
        double Stop_x = Start_x+ROI_w;
        double Stop_y = Start_y+ROI_h;

        int label_start_x = (Start_x/img_w)*label_size_w;
        int label_start_y = (Start_y/img_h)*label_size_h;
        int label_stop_x = (Stop_x/img_w)*label_size_w;
        int label_stop_y = (Stop_y/img_h)*label_size_h;

        label_img->paintRect(QPoint(label_start_x,label_start_y),
                            QPoint(label_stop_x,label_stop_y) );
    }
    else{
        QMessageBox::critical(NULL, "error!", "open a picture please!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return;
    }
}

void Widget::startPointSlot(QPoint p){
    startPoint = p;

    if(capture!=NULL){

        double label_size_w = label_img->size().width();
        double label_size_h = label_img->size().height();
        double img_w = capture->get(3);
        double img_h = capture->get(4);
        double point_x = p.x();
        double point_y = p.y();

        int ROI_x = (point_x/label_size_w)*img_w;
        int ROI_y = (point_y/label_size_h)*img_h;

        ui->lineEdit_start_x->setText(QString::number(ROI_x));
        ui->lineEdit_start_y->setText(QString::number(ROI_y));
    }
    else{
        ui->lineEdit_start_x->setText(QString::number(0));
        ui->lineEdit_start_y->setText(QString::number(0));
    }
}

void Widget::stopPointSlot(QPoint p){
    if(capture!=NULL){
        double label_size_w = label_img->size().width();
        double label_size_h = label_img->size().height();
        double img_w = capture->get(3);
        double img_h = capture->get(4);
        double point_End_x = p.x();
        double point_End_y = p.y();
        double point_Start_x = startPoint.x();
        double point_Start_y = startPoint.y();

        int ROI_w = ((point_End_x-point_Start_x)/label_size_w)*img_w;
        int ROI_h = ((point_End_y-point_Start_y)/label_size_h)*img_h;


        ui->lineEdit_size_w->setText(QString::number(ROI_w));
        ui->lineEdit_size_h->setText(QString::number(ROI_h));
    }
    else{
        ui->lineEdit_size_w->setText(QString::number(0));
         ui->lineEdit_size_h->setText(QString::number(0));
    }

}

void Widget::openPathSlot(){
    QString file_name = QFileDialog::getOpenFileName(this,tr("画像"),".",
                                                    tr("Image File(*.png *.jpg *.bmp *.jepg)"));
    QFile file(file_name);
    if(!file.open(QIODevice::ReadOnly))
    {

        return;
    }
    else{
        ui->lineEdit_path->setText(file_name);
        capture = new cv::VideoCapture();
        capture->open(file_name.toStdString());
        cv::Mat frame;
        bool ret = capture->read(frame);
        if(!ret){
            QMessageBox::critical(NULL, "error!", "open a picture failed!", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
            return;
        }

        show_img(frame,label_img);
        ui->label_path->setText(file_name);
    }
}

void Widget::show_img(cv::Mat image, QLabel *label){
    cv::cvtColor(image, image, CV_BGR2RGB);
    QImage img =  QImage((const unsigned char*)(image.data),image.cols,image.rows,
                         image.cols*image.channels(),
                         QImage::Format_RGB888).scaled(label->width(), label->height());

     label->clear();
     label->setPixmap(QPixmap::fromImage(img));
}

Widget::~Widget()
{
    delete ui;
}

