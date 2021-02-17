#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QList>
#include <QKeyEvent>
#include <QPoint>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

enum direction{
    dirUp,
    dirDown,
    dirLeft,
    dirRight,
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    void init();
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

    //上下左右走
    void crawlUp();
    void crawlDown();
    void crawlLeft();
    void crawlRight();

    ~Widget();

protected:
    //一个单位的宽和高
    int unitWidth;
    int unitHeight;

    //一个单元的左上右下的坐标
    QPoint upperLeft;
    QPoint rightDown;

    QTimer *timer;
    bool gamerun;
    int crawlDirect;
    QRect food;
    bool crash;

protected slots:
    void refreshWindow();

private:
    Ui::Widget *ui;
    QList<QRect> snake;// 蛇身
};
#endif // WIDGET_H
