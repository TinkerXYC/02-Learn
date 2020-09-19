#include "widget.h"
#include "ui_widget.h"
#include "Qpainter"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    x = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    //QPainter P(this);
    QPainter p;
    p.begin(this);//指定当前窗口为绘图设备

    //p.drawPixmap(0,0,width(),height(),QPixmap("../Image/qqq.jpg"));
    p.drawPixmap(rect(),QPixmap("../Image/qqq.jpg"));
    QPen pen;
    pen.setWidth(5);
    pen.setColor(Qt::red);
    pen.setColor(QColor(220,220,192));
    pen.setStyle(Qt::DashDotDotLine);
    p.setPen(pen);
    p.drawLine(50,50,150,50);
    p.drawPixmap(x,180,80,80,QPixmap("../Image/提莫.jpg"));
    p.end();
}

void Widget::on_pushButton_clicked()
{
    x += 20;
    if(x > width())
    {
        x = 0;
    }
    update();
}
