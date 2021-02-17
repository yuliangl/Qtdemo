#include "widget.h"
#include "ui_widget.h"

#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    init();
}

void Widget::init(){
    resize(1024,672);
    unitHeight = 32;
    unitWidth = 32;

    gamerun = false;
    crawlDirect = dirUp;
    crash = false;

    QRect unitself(qrand()%(1024/32)*32, qrand()%(672/32)*32, unitWidth, unitHeight);
    snake.append(unitself);
    crawlUp();
    crawlUp();

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(refreshWindow()));

    food = QRect(qrand()%(1024/32)*32, qrand()%(672/32)*32,
               unitWidth, unitHeight);
}

void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);

    //添加背景
    QPixmap background;
    background.load("D:/Qtproject/Qtdemo/image/background.jpg");
    painter.drawPixmap(0, 0, 1024, 672, background);

    //画蛇身
    QPen pen(Qt::darkGreen, Qt::SolidLine);
    QBrush brush(Qt::green, Qt::SolidPattern);
    painter.setPen(pen);
    painter.setBrush(brush);
    for (int i = 0;  i< snake.length(); i++) {
        painter.drawRect(snake[i]);
    }
    //画食物
    painter.drawRect(food);

    QFont font("方正舒体", 100, QFont::ExtraLight, false);
    painter.setFont(font);
    if(crash){
        painter.drawText(70, 672/2, QString("GAME OVER！"));
    }

}

void Widget::crawlUp(){
    upperLeft = QPoint(snake[0].x(), snake[0].y()-unitHeight);
    rightDown = snake[0].topRight();
    snake.insert(0,QRect(upperLeft, rightDown));
}
void Widget::crawlDown(){
    upperLeft = snake[0].bottomLeft();
    rightDown = QPoint(upperLeft.x() + unitWidth, upperLeft.y() + unitHeight);
    snake.insert(0,QRect(upperLeft, rightDown));
}
void Widget::crawlLeft(){
    rightDown = snake[0].bottomLeft();
    upperLeft = QPoint(rightDown.x() - unitWidth, rightDown.y() - unitHeight);
    snake.insert(0,QRect(upperLeft, rightDown));
}
void Widget::crawlRight(){
    upperLeft = snake[0].topRight();
    rightDown = QPoint(upperLeft.x() + unitWidth, upperLeft.y()+unitHeight);
    snake.insert(0,QRect(upperLeft, rightDown));
}

void Widget::keyPressEvent(QKeyEvent *event){

        switch (event->key()) {
        case Qt::Key_Up:
            if(crawlDirect != dirDown){
                crawlDirect = dirUp;
            }
            break;
        case Qt::Key_Down:
            if(crawlDirect != dirUp){
                crawlDirect = dirDown;
            }
            break;
        case Qt::Key_Left:
            if(crawlDirect != dirRight){
                crawlDirect = dirLeft;
            }
            break;
        case Qt::Key_Right:
            if(crawlDirect != dirLeft){
                crawlDirect = dirRight;
            }
            break;
        case Qt::Key_Space:
            if(gamerun){
                gamerun = false;
                timer->stop();
            } else {
                gamerun = true;
                timer->start(200);
            }
            break;

        }
}

void Widget::refreshWindow(){
    int count = 1;
    //吃到食物把食物加到蛇身上，即每个方向都是同时加两个
    if(snake[0].intersects(food)){
        count++;
        food = QRect(qrand()%(1024/32)*32, qrand()%(672/32)*32,
                   unitWidth, unitHeight);
    }
    //判断自身相撞
    for(int i=0; i<snake.length(); i++){
        for(int j=i+1; j<snake.length(); j++){
            if(snake[i] == snake[j]){
                crash = true;
                timer->stop();
            }
        }
    }
    while(count--){
        switch (crawlDirect) {
        case dirUp:
            crawlUp();
            if(snake[0].y() < 0){
                timer->stop();
                crash = true;
            }
            break;
        case dirDown:
            crawlDown();
            if(snake[0].y() > 672){
                timer->stop();
                crash = true;
            }
            break;
        case dirLeft:
            crawlLeft();
            if(snake[0].x() < 0){
                timer->stop();
                crash = true;
            }
            break;
        case dirRight:
            crawlRight();
            if(snake[0].x() > 1024){
                timer->stop();
                crash = true;
            }
            break;

        }
    }
    snake.removeLast();
    update();
}

Widget::~Widget()
{
    delete ui;
}

