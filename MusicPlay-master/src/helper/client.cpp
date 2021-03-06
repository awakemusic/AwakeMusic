﻿#include "client.h"
#include <QtNetwork>
#include <QImageReader>
#include <iostream>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QGridLayout>

Client::Client()
{
    tcpSocket = new QTcpSocket();

    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    inBlock = 0;

//    button = new QPushButton("play");
//    QPushButton *button2 = new QPushButton("play2");
//    button->setDefault(true);
//    QDialogButtonBox *buttonBox = new QDialogButtonBox;
//    buttonBox->addButton(button, QDialogButtonBox::ActionRole);
//    buttonBox->addButton(button2,QDialogButtonBox::ActionRole);


//    newConnect();
//    connect(button, &QPushButton::clicked, this, &Client::sendData);
//    sendData();

    //connect(tcpSocket, &QIODevice::readyRead, this, &Client::showPicture);

    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &Client::displayError);

    //这里关联了两个信号到自定义的槽上，当有可读的数据时会发射readyRead（）信号，当发生错误时会发射error（）信号。下面添加newConnect（）槽的定义。

//    QGridLayout *mainLayout = new QGridLayout(this);
//    mainLayout->addWidget(buttonBox, 0, 0);

}


void Client::sendData(QString data)
{
    newConnect();
//    QString data = "xiaochou";
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_10);

    out << quint32(data.size());

    out << data;

   // qDebug() << m;

    tcpSocket->write(block);
    block.resize(0);
    connect(tcpSocket, &QIODevice::readyRead, this, &Client::showString);
}

void Client::newConnect()
{
    blockSize = 0;
    tcpSocket->abort();
    tcpSocket->connectToHost("10.253.110.152", 6667);
    //connect(tcpSocket, &QIODevice::readyRead,this,&Client::showPicture);
}

void Client::showString()
{
    QDataStream in(tcpSocket);
    //设置数据流版本，这里要和服务器端相同。
    in.setVersion(QDataStream::Qt_5_10);

    //如果这是刚开始接受数据
    if(blockSize==0){
        //判断接收数据是否大于两字节，也就是文件的大小信息所占的空间
        //如果时则保存到blockSize变量中，否则直接返回，继续接受数据
        if(tcpSocket->bytesAvailable() < (int)sizeof(quint32)) return;
        in >> blockSize;
    }
    //如果没有得到全部的数据，则返回，继续接收数据
    if(tcpSocket->bytesAvailable()<blockSize) return;
    //将接收到的数据存放到变量中
    //message顺序：中文，英文，歌手，专辑，图片，文件
    QString name, pinyin,singer,album;
    in >> name >> pinyin >> singer >>album;
    if(name.isNull()&&pinyin.isNull()&&singer.isNull() && album.isNull())
    {
        qDebug()<<"kong";
    }
    emit signalSendInfo(name,singer,album);
    emit signalSendPinYin(name,pinyin);
    //显示接收到的数据
    qDebug()<<name << pinyin << singer <<album;
    blockSize = blockSize - name.size() - pinyin.size() - singer.size()-album.size();

    //    while(tcpSocket->bytesAvailable()>0)
    //    {
    //        if(blockSize==0){
    //            if(tcpSocket->bytesAvailable()<sizeof(quint32))
    //                return;
    //            in>>blockSize;
    //        }
    // if(tcpSocket->bytesAvailable()<blockSize) return;
    QByteArray array = tcpSocket->read(blockSize);
    QBuffer buffer(&array);
    buffer.open(QIODevice::ReadOnly);

    QImageReader reader(&buffer,"JPG");
    QImage image = reader.read();
    if(!image.isNull())
    {
        QString filename = "/root/image/test.jpg";
        image.save(filename);
       // tcpSocket->close();
        emit signalShowImage(image);
    }
    blockSize = 0;

    if(bytesReceived <= sizeof(qint32)*2)
    {
        if(tcpSocket->bytesAvailable() >= sizeof(qint32)*2)
        {
            in >> totalBytes >> fileNameSize;
            qDebug() << totalBytes;
            qDebug() << fileNameSize;
            bytesReceived += sizeof(qint32)*2;
        }
        if(tcpSocket->bytesAvailable() >= fileNameSize && (fileNameSize != 0))
        {
            in >> fileName;
            //fileName = "music";
            qDebug() << "readd";
            bytesReceived += fileNameSize;
            QString name = "/root/MusicPlay-master/Lrc/" + fileName;
            localFile = new QFile(name);
            qDebug() << fileName;
            if(!localFile->open(QFile::WriteOnly))
            {
                qDebug() << "file:open error!";
                return;
            }
        }else{
            return;
        }
    }
    if(bytesReceived < totalBytes ){
        bytesReceived += tcpSocket->bytesAvailable();
//        m_lrcText->setText(tcpSocket->readAll());
        inBlock = tcpSocket->readAll();
        qDebug() << inBlock;
        localFile->write(inBlock);
        qDebug() << "writing";

        inBlock.resize(0);
    }
    if(bytesReceived == totalBytes){

        localFile->close();
        tcpSocket->close();
    qDebug() << "accept success";

    }

}

void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<tcpSocket->errorString();
}

//void Client::receivePlaylist()
//{
//    if(bytesReceived <= sizeof(qint32)*2)
//    {
//        if(tcpSocket->bytesAvailable() >= sizeof(qint32)*2)
//        {
//            in >> totalBytes >> fileNameSize;
//            qDebug() << totalBytes;
//            qDebug() << fileNameSize;
//            bytesReceived += sizeof(qint32)*2;
//        }
//        if(tcpSocket->bytesAvailable() >= fileNameSize && (fileNameSize != 0))
//        {
//            in >> fileName;
//            //fileName = "music";
//            qDebug() << "readd";
//            bytesReceived += fileNameSize;
//            QString name = "/root/image/" + fileName;
//            localFile = new QFile(name);
//            qDebug() << fileName;
//            if(!localFile->open(QFile::WriteOnly))
//            {
//                qDebug() << "file:open error!";
//                return;
//            }
//        }else{
//            return;
//        }
//    }
//    if(bytesReceived < totalBytes ){
//        bytesReceived += tcpSocket->bytesAvailable();
////        m_lrcText->setText(tcpSocket->readAll());
//        inBlock = tcpSocket->readAll();
//        qDebug() << inBlock;
//        localFile->write(inBlock);
//        qDebug() << "writing";

//        inBlock.resize(0);
//    }
//    if(bytesReceived == totalBytes){

//        localFile->close();
//        tcpSocket->close();
//    qDebug() << "accept success";

//    }
//    bytesReceived = 0;
//    totalBytes = 0;

//}
