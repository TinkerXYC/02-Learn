#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //分配空间，指定父对象
    udpSocket = new QUdpSocket(this);

    //绑定
    udpSocket->bind(8888);

    setWindowTitle("Server Port：8888");

    //当对方成功发送数据过来
    //自动触发readyRead()
    connect(udpSocket,&QUdpSocket::readyRead, this,&Widget::dealMsg);
}
void Widget::dealMsg()
{
    char buf[1024] = {0};
    QHostAddress cliAddr;
    quint16 port;

    qint64 len = udpSocket->readDatagram(buf,sizeof(buf),&cliAddr,&port);
    if(len > 0)
    {
        QString str = QString ("[%1:%2] %3")
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

void Widget::on_ButtonSend_clicked()
{
    //先获取对方的IP和端口
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();

    QString str = ui->textEdit->toPlainText();

    udpSocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);
}
