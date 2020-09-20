#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);
    tcpServer = NULL;
    tcpSocket = NULL;
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8888);
    setWindowTitle("服务器：8888");
    connect(tcpServer,&QTcpServer::newConnection,
            [=](){
                tcpSocket = tcpServer->nextPendingConnection();
                QString ip = tcpSocket->peerAddress().toString();
                qint16 port = tcpSocket->peerPort();
                QString temp = QString("[%1:%2]:连接成功")
                        .arg(ip).arg(port);
                ui->textEditRead->setText(temp);

                connect(tcpSocket,&QTcpSocket::readyRead,
                        [=]()
                        {
                          QByteArray array = tcpSocket->readAll();
                          ui->textEditRead->append(array);
                        }

                        );
            }
            );
    //tcpSocket = new QTcpSocket(this);

}

ServerWidget::~ServerWidget()
{
    delete ui;
}

void ServerWidget::on_ButtonSend_clicked()
{
    if(NULL == tcpSocket){
        return;
    }
    QString str = ui->textEditWrite->toPlainText();
    tcpSocket->write(str.toUtf8().data());
}

void ServerWidget::on_ButtonClose_clicked()
{
    if(NULL == tcpSocket){
        return;
    }
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket = NULL;
}
