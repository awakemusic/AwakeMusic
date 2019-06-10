#include "server.h"
#include <QtNetwork>
#include <QTcpServer>

//#include <QtDebug>

Server::Server(QWidget *parent)
    : ui(new Ui::MainWindow)
   // : QPixmap(":/root/album.jpg").save(&buffer,"JPG")
{
    ui->setupUi(this);
    tcpServer = new QTcpServer();
    QPixmap("/root/album.jpg").save(&buffer,"JPG");
    if(!tcpServer->listen(QHostAddress::LocalHost,6666)){
        qDebug()<<tcpServer->errorString();
        tcpServer->close();
    }
    //调用了qtcpserver类的listen（）函数来监听到来的连接，这里监听了本地主机的6666端口，这样可以实现客户端和服务端在同一台计算机上运行并通信，也可以换成其他地址。
    connect(tcpServer, &QTcpServer::newConnection, this, &Server::sendMessage);
    //一旦有客户端连接到服务器就会发射newConnection（）信号。
}

Server::~Server()
{}

//void Server::sendPicture()
//{
//    QByteArray block;
//    QDataStream out(&block,QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_5_10);
//    out<<(quint32)buffer.data().size();
//    block.append(buffer.data());
//    clientConnetion->write(block);

//}

void Server::sendMessage()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

//    out.setVersion(QDataStream::Qt_5_10);
//    out<<(quint16)0;
//    out<<tr("hello TCP!!!");
//    out.device()->seek(0);
//    out<<(quint16)(block.size() - sizeof(quint16));

    out<<(quint32)buffer.data().size();
    block.append(buffer.data());

    QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, &QAbstractSocket::disconnected,
            clientConnection, &QObject::deleteLater);
    clientConnection->write(block);
    clientConnection->disconnectFromHost();
    ui->label->setText("send message successful!!!");

}
