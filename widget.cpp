#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer.setInterval(40);
    timer.start();
    connect(&timer,SIGNAL(timeout()),this,SLOT(changeColor()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint (QPainter:: Antialiasing);
    int w = this->width();
    int h = this->height();
    QPoint center(w/2,h/2);
    painter.setBrush(QBrush(QColor::fromRgb(r,g,b)));
   // painter.drawEllipse(center,w/5,w/5);
    painter.drawRect(0,0,w,h);
    if(r>254 || r<1) rSpeed *=-1;
    if(g>253 || g<2) gSpeed *=-1;
    if(b>252 || b<3) bSpeed *=-1;
    r = r+rSpeed;
    g = g+gSpeed;
    b = b+bSpeed;

}

void Widget::changeColor()
{
    this->repaint();
}




