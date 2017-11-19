#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <Qtimer>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
    QTimer timer;
    int r = 1;
    int g = 2;
    int b = 3;
    void paintEvent(QPaintEvent *e);
    int rSpeed = 1;
    int gSpeed = 2;
    int bSpeed = 3;
private slots:
    void changeColor();
};

#endif // WIDGET_H
