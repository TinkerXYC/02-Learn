#include "widget.h"
#include "ui_widget.h"
#include <QHostAddress>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    udpSocket = new QUdpSocket(this);

    udpSocket->bind(8888);

    setWindowTitle("服务器端口为：8888");

    connect(udpSocket,&QUdpSocket::readyRead,this,&Widget::dealMsg);

}
void Widget::dealMsg()
{
    char buf[1024] = {0};
    QHostAddress cliAddr;
    qint16 port;
    qint64 len = udpSocket->readDatagram(buf,sizeof(buf),&cliAddr,&port);
    if (len > 0){
        QString str = QString("[%1：%2] %3")
                .arg(cliAddr.toString())
                .arg(port)
                .arg(buf);
        ui->textEdit->setText(str);
    }
}
Widget::~Widget()
{
    delete ui;
}
