#ifndef MYLABEL_H
#define MYLABEL_H

#include <QObject>
#include <QLabel>
#include <QPainter>
#include <QPoint>
#include <QColor>
#include <QPen>
#include <QMouseEvent>
#include <qdebug.h>

class myLabel:public QLabel
{
    Q_OBJECT

public:
    myLabel(QWidget *parent);

    virtual void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;

    QPoint getStartPoint();
    QPoint getEndPoint();
    void setLineColor(const QColor lineColor);
    void setLineSize(const int lineSize);
    void clear();
    void paintRect(QPoint start, QPoint stop);

private:
    QPoint startPoint;
    QPoint endPoint;
    QColor lineColor;
    int lineSize;
    bool isPressed;

signals:
    void startPointSignal(QPoint p);
    void stopPointSignal(QPoint p);

};
#endif // MYLABEL_H
