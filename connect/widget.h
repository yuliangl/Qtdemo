#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

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
    void on_connect_But_clicked();

    void on_send_But_clicked();

    void on_close_But_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *tcpSocket;
};
#endif // WIDGET_H
