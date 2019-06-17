#include "client.h"
#include <QtNetwork>
#include <QImageReader>
#include <iostream>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QGridLayout>

Client::Client()
{
    tcpSocket = new QTcpSocket();

    button = new QPushButton("play");
    QPushButton *button2 = new QPushButton("play2");
    button->setDefault(true);
    QDialogButtonBox *buttonBox = new QDialogButtonBox;
    buttonBox->addButton(button, QDialogButtonBox::ActionRole);
    buttonBox->addButton(button2,QDialogButtonBox::ActionRole);


    connect(button, &QPushButton::clicked, this, &Client::on_connectButton_clicked);

    //connect(tcpSocket, &QIODevice::readyRead, this, &Client::showPicture);

    connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
            this, &Client::displayError);

    //这里关联了两个信号到自定义的槽上，当有可读的数据时会发射readyRead（）信号，当发生错误时会发射error（）信号。下面添加newConnect（）槽的定义。

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(buttonBox, 0, 0);

}

void Client::sendData()
{
    QString data = "xiaochou";
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_10);

    out << quint32(data.size());

    out << data;

    tcpSocket->write(block);
    block.resize(0);
    connect(tcpSocket, &QIODevice::readyRead, this, &Client::showPicture);
}

void Client::newConnect()
{
    blockSize = 0;
    tcpSocket->abort();
    tcpSocket->connectToHost("localhost", 6667);
    sendData();
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
        if(tcpSocket->bytesAvailable() < (int)sizeof(quint32)) return;
        in >> blockSize;
    }
    //如果没有得到全部的数据，则返回，继续接收数据
    if(tcpSocket->bytesAvailable()<blockSize) return;
    //将接收到的数据存放到变量中
    QString message1, message2;
    in >> message1 >> message2;
    if(message1.isNull())
    {
        qDebug()<<"kong";
    }
    //显示接收到的数据
    qDebug()<<message1 << message2;

    //    while(tcpSocket->bytesAvailable()>0)
    //    {
    //        if(blockSize==0){
    //            if(tcpSocket->bytesAvailable()<sizeof(quint32))
    //                return;
    //            in>>blockSize;
    //        }
    // if(tcpSocket->bytesAvailable()<blockSize) return;
    QByteArray array = tcpSocket->read(blockSize - message1.size()-message2.size());
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
   // tcpSocket->close();
}

void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<tcpSocket->errorString();
}

void Client::on_connectButton_clicked()
{
    newConnect();
}
