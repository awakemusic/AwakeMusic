#include "client.h"
#include <QtNetwork>
#include <QImageReader>
#include <iostream>

Client::Client()
{
    tcpSocket = new QTcpSocket();
    newConnect();
    connect(tcpSocket, &QIODevice::readyRead, this, &Client::showPicture);
    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &Client::displayError);

    //这里关联了两个信号到自定义的槽上，当有可读的数据时会发射readyRead（）信号，当发生错误时会发射error（）信号。下面添加newConnect（）槽的定义。

}

QImage Client::getImage()
{
    return image;
}

void Client::newConnect()
{
    //初始化数据大小信息为0。
    blockSize = 0;

    //取消已有的连接。
    tcpSocket->abort();
    tcpSocket->connectToHost("localhost", 6666);
}

void Client::showPicture()
{
    QDataStream in(tcpSocket);
    //设置数据流版本，这里要和服务器端相同。
    in.setVersion(QDataStream::Qt_5_10);

    //如果这是刚开始接受数据
    if(blockSize==0){
        //判断接收数据是否大于两字节，也就是文件的大小信息所占的空间
        //如果时则保存到blockSize变量中，否则直接返回，继续接受数据
        if(tcpSocket->bytesAvailable() < 2*(int)sizeof(quint32)) return;
        in >> blockSize;
    }
    //如果没有得到全部的数据，则返回，继续接收数据
    if(tcpSocket->bytesAvailable()<blockSize) return;
    //将接收到的数据存放到变量中
    QString message;
    in >> message;
    //显示接收到的数据
    qDebug()<<message;

    //    while(tcpSocket->bytesAvailable()>0)
    //    {
    //        if(blockSize==0){
    //            if(tcpSocket->bytesAvailable()<sizeof(quint32))
    //                return;
    //            in>>blockSize;
    //        }
    // if(tcpSocket->bytesAvailable()<blockSize) return;
    QByteArray array = tcpSocket->read(blockSize - message.size());
    QBuffer buffer(&array);
    buffer.open(QIODevice::ReadOnly);

    QImageReader reader(&buffer,"JPG");
    QImage image = reader.read();
    if(image.isNull())
    {
        qDebug()<<"kong";
    }
    if(!image.isNull())
    {

        filename = "/root/image/test.jpg";
        image.save(filename);
    }
    blockSize = 0;


}




void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<tcpSocket->errorString();
}