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
    if(!tcpServer->listen(QHostAddress::LocalHost,6667)){
        qDebug()<<tcpServer->errorString();
        tcpServer->close();
    }
    totalBytes = 0;
    bytesToWrite = 0;
    payloadSize = 64*1024;


    //调用了qtcpserver类的listen（）函数来监听到来的连接，这里监听了本地主机的6666端口，这样可以实现客户端和服务端在同一台计算机上运行并通信，也可以换成其他地址。

    //connect(tcpServer, &QTcpServer::newConnection, this, &Server::sendMessage);

    //the need a button to touch the event,then will start connection again
//    if(!tcpServer->listen(QHostAddress::LocalHost,6666)){
//        qDebug()<<tcpServer->errorString();
//        tcpServer->close();
//    }
   // tcpServer = new QTcpServer();
    //clientConnection = tcpServer->nextPendingConnection();

    //connect(clientConnection,&QIODevice::readyRead,this,&Server::update);
connect(tcpServer, &QTcpServer::newConnection, this, &Server::sendMessage);
//connect(clientConnection,&QIODevice::bytesWritten,this,&Server::update);




   // clientConnection = tcpServer->nextPendingConnection();

    //connect(clientConnection,&QIODevice::readyRead,this,&Server::update);

    //一旦有客户端连接到服务器就会发射newConnection（）信号。
}


Server::~Server()
{}



void Server::sendMessage()
{
       clientConnection = tcpServer->nextPendingConnection();



      QDataStream sendOut(&outBlock, QIODevice::WriteOnly);

      sendOut.setVersion(QDataStream::Qt_5_10);

      QString mess = "消愁";

     sendOut<<(quint64)(mess.size()+buffer.data().size());

      sendOut<<mess;
      qDebug() << "send";

      outBlock.append(buffer.data());



        connect(clientConnection, &QAbstractSocket::disconnected,
                clientConnection, &QObject::deleteLater);

      clientConnection->write(outBlock);

      ui->label->setText("send message successful!!!");

      outBlock.resize(0);



      qDebug() << "finish this transmission.";



      clientConnection->reset();


      sendOut.device()->seek(0);

      connect(clientConnection,&QIODevice::bytesWritten,this,&Server::update);



      fileName = "/root/image/music";
      localFile = new QFile(fileName);

      qDebug() << localFile->exists();
      if(!localFile->open(QFile::ReadOnly)){
          qDebug() << "client:open file error";
          return;
      }
      qDebug() << "start to write";
      totalBytes = localFile->size();
      qDebug() << totalBytes;
      //QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
     // sendOut.setVersion(QDataStream::Qt_5_10);
      QString currenFileName = fileName.right(fileName.size()-fileName.lastIndexOf('/')-1);
      sendOut << qint64(0) << qint64(0) << currenFileName;
      qDebug() << currenFileName.size();
      totalBytes += outBlock.size();
      qDebug() << totalBytes;

      //sendOut << qint64(0) << qint64(0) << currenFileName;
      sendOut.device()->seek(0);
      sendOut << totalBytes << qint64((outBlock.size()-sizeof(qint64)*2));
      //totalBytes += outBlock.size();
      //outBlock.resize(0);
      bytesToWrite = totalBytes-clientConnection->write(outBlock);
      qDebug() << bytesToWrite;
      outBlock.resize(0);
    //clientConnection = tcpServer->nextPendingConnection();
       // connect(clientConnection,&QTcpSocket::connected,this,&Server::startTransfer);


        //connect(clientConnection,&QIODevice::readyRead,this,&Server::update);
      while(bytesToWrite){
      outBlock = localFile->read(qMin(bytesToWrite,payloadSize));
      //qDebug() << s;
      qDebug() << "read";
      //tcpSocket->write(outBlock);
      //qDebug() << outBlock;
      bytesToWrite -= (int)clientConnection->write(outBlock);
      outBlock.resize(0);
}


         localFile->close();

         clientConnection->close();




}

void Server::update(){
    if(bytesToWrite>0)
    {
        outBlock = localFile->read(qMin(bytesToWrite,payloadSize));
        //qDebug() << s;
        qDebug() << "read";
        //tcpSocket->write(outBlock);
        //qDebug() << outBlock;
        bytesToWrite -= (int)clientConnection->write(outBlock);
        outBlock.resize(0);
        //clientConnection->waitForBytesWritten();
    }
    else
    {
       localFile->close();

       clientConnection->close();

    }
}

void Server::startTransfer(){

    fileName = "/root/image/music";
    localFile = new QFile(fileName);
    qDebug() << localFile->exists();
    if(!localFile->open(QFile::ReadOnly)){
        qDebug() << "client:open file error";
        return;
    }
    qDebug() << "start to write";
    totalBytes = localFile->size();
    qDebug() << totalBytes;
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_5_10);
    QString currenFileName = fileName.right(fileName.size()-fileName.lastIndexOf('/')-1);
    sendOut << qint64(0) << qint64(0) << currenFileName;
    totalBytes += outBlock.size();
    sendOut.device()->seek(0);
    sendOut << totalBytes << qint64((outBlock.size()-sizeof(qint64)*2));
    bytesToWrite = totalBytes-tcpSocket->write(outBlock);
    outBlock.resize(0);
}
