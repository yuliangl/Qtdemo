#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>
#include <QMessageBox>
#include "myLabel.h"
#include <QPoint>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void openPathSlot();
    void startPointSlot(QPoint p);
    void stopPointSlot(QPoint P);
    void pointTextChangeSlot(QString);

private:
    Ui::Widget *ui;
    void show_img(cv::Mat image, QLabel *label);
    myLabel *label_img;
    cv::VideoCapture *capture = NULL;
    QPoint startPoint;


};
#endif // WIDGET_H
