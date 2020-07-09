#include "myLabel.h"

myLabel::myLabel(QWidget *parent):QLabel(parent){
        this->startPoint = QPoint(0,0);
        this->endPoint = QPoint(0,0);
        this->lineColor = QColor(Qt::red);
        this->lineSize = 2;
        this->isPressed = false;
}

void myLabel::paintRect(QPoint start, QPoint stop){
    startPoint = start;
    endPoint = stop;
    update();
}

void myLabel::paintEvent(QPaintEvent *event){
    QLabel::paintEvent(event);

    QPainter painter(this);
    QPen pen;
    pen.setColor(lineColor);
    pen.setWidth(lineSize);
    painter.setPen(pen);
    painter.drawRect(QRect(startPoint.x(), startPoint.y(),
                           endPoint.x()-startPoint.x(), endPoint.y()-startPoint.y()));
}

void myLabel::mousePressEvent(QMouseEvent *ev){
   startPoint = ev->pos();
   endPoint = ev->pos();

   isPressed = true;
   emit startPointSignal(startPoint);
}

void myLabel::mouseMoveEvent(QMouseEvent *ev){
    if(isPressed){
        endPoint = ev->pos();

        emit stopPointSignal(endPoint);
        update();
    }
}

void myLabel::mouseReleaseEvent(QMouseEvent *ev){
    isPressed = false;
    update();
}

void myLabel::setLineColor(const QColor lineColor){
    this->lineColor = lineColor;
}

void myLabel::setLineSize(const int lineSize){
    this->lineSize = lineSize;
}

QPoint myLabel::getStartPoint(){
    return startPoint;
}

QPoint myLabel::getEndPoint(){
    return endPoint;
}

void myLabel::clear(){
    startPoint = QPoint(0 ,0);
    endPoint = QPoint(0, 0);
    update();
}


