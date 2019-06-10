#include "server.h"
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>
#include<iostream>

//#include <QtDebug>

Server::Server(QWidget *parent)
    : ui(new Ui::MainWindow)
    // : QPixmap("/root/album.jpg").save(&buffer,"JPG")
{
    ui->setupUi(this);
    tcpServer = new QTcpServer();
    QPixmap("/root/myself.jpg").save(&buffer,"JPG");
    if(!tcpServer->listen(QHostAddress::LocalHost,6666)){
        qDebug()<<tcpServer->errorString();
        tcpServer->close();
    }
    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
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
//        QByteArray block;
//        QDataStream out(&block, QIODevice::WriteOnly);

//        out.setVersion(QDataStream::Qt_5_10);
//        QString mess = "hello TCP!!!";
//        out<<(quint32)(mess.size()+buffer.data().size());
//        out<<mess;
//       // out<<tr("hello TCP!!!");
//       // out.device()->seek(0);
//       // out<<(quint16)(block.size() - sizeof(quint16));

//        //out<<(quint32)buffer.data().size();
//        block.append(buffer.data());

//        QTcpSocket *clientConnection = tcpServer->nextPendingConnection();
//        connect(clientConnection, &QAbstractSocket::disconnected,
//                clientConnection, &QObject::deleteLater);
//        clientConnection->write(block);
//       // std::cout<<"write";
//       // clientConnection->disconnectFromHost();
//        ui->label->setText("send message successful!!!");
    clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection,&QIODevice::readyRead,this,&Server::update);
    //clientConnection->disconnectFromHost();
}

void Server::update(){

    QDataStream in(clientConnection);
    in.setVersion(QDataStream::Qt_5_10);

    if(bytesReceived <= sizeof(qint64)*2)
    {
        if(clientConnection->bytesAvailable() >= sizeof(qint64)*2)
        {
            in >> totalBytes >> fileNameSize;
            bytesReceived += sizeof(qint64)*2;
        }
        if(clientConnection->bytesAvailable() >= fileNameSize && (fileNameSize != 0))
        {
            in >> fileName;
            qDebug() << "readd";
            bytesReceived += fileNameSize;
            QString name = "/root/" + fileName;
            localFile = new QFile(name);
            if(!localFile->open(QFile::WriteOnly))
            {
                qDebug() << "server:open error!";
                return;
            }
        }else{
            return;
        }
    }
    if(bytesReceived < totalBytes){
        bytesReceived += clientConnection->bytesAvailable();
        inBlock = clientConnection->readAll();
        localFile->write(inBlock);
        qDebug() << "writing";
       // qDebug() << inBlock;
        inBlock.resize(0);
    }
    if(bytesReceived == totalBytes){
        clientConnection->close();
        localFile->close();
        qDebug() << "accept success";
    }

}
