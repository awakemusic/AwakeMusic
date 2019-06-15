#include "client.h"
#include <QtNetwork>
#include <QImageReader>
#include <QMessageBox>
#include <QFile>
#include <QTcpSocket>

Client::Client(/*QWidget *parent*/)
    //: ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    newConnect();
    totalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;
    inBlock = 0;
   connect(tcpSocket, &QIODevice::readyRead, this, &Client::readMessage);
  //connect(tcpSocket,&QIODevice::readyRead,this,&Client::update);
   // connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
    //         this, &Client::displayError);
//    connect(ui->connectButton, &QPushButton::clicked,
//            this, &Client::on_connectButtion_clicked);
//   connect(tcpSocket,&QTcpSocket::connected,this,&Client::startTransfer);
//   connect(tcpSocket,&QIODevice::bytesWritten,this,&Client::update);

    //newConnect();


     connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
              this, &Client::displayError);







    //这里关联了两个信号到自定义的槽上，当有可读的数据时会发射readyRead（）信号，当发生错误时会发射error（）信号。下面添加newConnect（）槽的定义。
}
void Client::update(){

    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_10);

    if(bytesReceived <= sizeof(qint64)*2)
    {
        if(tcpSocket->bytesAvailable() >= sizeof(qint64)*2 && fileNameSize == 0)
        {
            in >> totalBytes >> fileNameSize;
            bytesReceived += sizeof(qint64)*2;
        }
        if(tcpSocket->bytesAvailable() >= fileNameSize && (fileNameSize != 0))
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
        qDebug() << tcpSocket->bytesToWrite();
        bytesReceived += tcpSocket->bytesAvailable();
        inBlock = tcpSocket->readAll();
         qDebug() << inBlock;
        localFile->write(inBlock);
        qDebug() << "writing";

        inBlock.resize(0);
    }
    if(bytesReceived == totalBytes){
        tcpSocket->close();
        localFile->close();
        qDebug() << "accept success";
    }

}


Client::~Client()
{}

void Client::newConnect()
{
    //初始化数据大小信息为0。
    blockSize = 0;

    //取消已有的连接。
    tcpSocket->abort();
    tcpSocket->connectToHost("localhost", 6667);
}

void Client::readMessage()
{
    QDataStream in(tcpSocket);
    //设置数据流版本，这里要和服务器端相同。
    in.setVersion(QDataStream::Qt_5_10);


    if(blockSize==0){
        //判断接收数据是否大于两字节，也就是文件的大小信息所占的空间
        //如果时则保存到blockSize变量中，否则直接返回，继续接受数据
        if(tcpSocket->bytesAvailable()<(int)sizeof(quint64)) return;
        in >> blockSize;
        }
    //如果没有得到全部的数据，则返回，继续接收数据
    if(tcpSocket->bytesAvailable()<blockSize) return;
    //将接收到的数据存放到变量中
    in >> message ;

    //显示接收到的数据
    qDebug()<<message;
    QByteArray array = tcpSocket->read(blockSize-message.size());
    QBuffer buffer(&array);
    buffer.open(QIODevice::ReadOnly);
    QImageReader reader(&buffer,"JPG");
    QImage image = reader.read();
    if(image.isNull()){
        qDebug()<< "kong";
    }
    else{
        QString filename = "/root/image/myself.jpg";
        image.save(filename);
        qDebug() << "save image success!";
    }

    if(bytesReceived <= sizeof(qint64)*2)
    {
        if(tcpSocket->bytesAvailable() >= sizeof(qint64)*2)
        {
            in >> totalBytes >> fileNameSize;
            qDebug() << totalBytes;
            qDebug() << fileNameSize;
            bytesReceived += sizeof(qint64)*2;
        }
        if(tcpSocket->bytesAvailable() >= fileNameSize && (fileNameSize != 0))
        {
            in >> fileName;
            //fileName = "music";
            qDebug() << "readd";
            bytesReceived += fileNameSize;
            QString name = "/root/" + fileName;
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
        inBlock = tcpSocket->readAll();
        qDebug() << inBlock;
        localFile->write(inBlock);
        qDebug() << "writing";

        inBlock.resize(0);
    }
    if(bytesReceived == totalBytes){

        localFile->close();
        //tcpSocket->close();
    qDebug() << "accept success";

    }
    //如果这是刚开始接受数据



}

void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<tcpSocket->errorString();
}
