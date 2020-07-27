#include <QHostAddress>
#include <QDebug>
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpSocket = NULL;

    tcpSocket = new QTcpSocket(this);
    tcpSocket->setReadBufferSize(4096);

    connect(tcpSocket, QTcpSocket::connected,
            [=](){
                  ui->textEdit_read->setText("connect finish");
                 }
            );
    connect(tcpSocket, QTcpSocket::readyRead,
            [=](){
                 QByteArray array = tcpSocket->readAll();
                 ui->textEdit_read->append(array);
                 }
            );
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_connect_But_clicked()
{
    //get IP and Port
    QString ip = ui->lineEdit_IP->text();
    qint16 port = ui->lineEdit__port->text().toInt();
//    QString ip = "192.168.3.9";
//    qint32 port = 50001;
//    ui->lineEdit_IP->setText("192.168.3.9");
//    ui->lineEdit__port->setText("50001");

    //connect to server
    tcpSocket->connectToHost(QHostAddress(ip), port);
}

void Widget::on_send_But_clicked()
{
    QString str = ui->textEdit_write->toPlainText();
    tcpSocket->write(str.toUtf8().data());

    qDebug() <<"send pushed";

}

void Widget::on_close_But_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
