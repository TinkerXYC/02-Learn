#include "clientwidget.h"
#include "ui_clientwidget.h"
#include "QHostAddress"

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    tcpSocket = NULL;
    tcpSocket = new QTcpSocket(this);
    setWindowTitle("客户端");
    connect(tcpSocket,&QTcpSocket::connected,
            [=]()
            {
                ui->textEditRead->setText("成功和服务器建立好连接");
            }
            );
    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
    {
        QByteArray array = tcpSocket->readAll();
        ui->textEditRead->append(array);
    }
            );

}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_ButtonConnect_clicked()
{
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();
    tcpSocket->connectToHost(QHostAddress(ip),port);
}

void ClientWidget::on_pushButtonSend_clicked()
{
    QString str = ui->textEditWrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());
}

void ClientWidget::on_pushButton_3_clicked()
{
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
