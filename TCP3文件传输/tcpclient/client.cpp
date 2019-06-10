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
//    connect(ui->connectButton, &QPushButton::clicked,
//            this, &Client::on_connectButtion_clicked);
    connect(tcpSocket,&QTcpSocket::connected,this,&Client::startTransfer);
    connect(tcpSocket,&QIODevice::bytesWritten,this,&Client::update);
    //connect(tcpSocket, &QIODevice::readyRead, this, &Client::readMessage);
     connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
              this, &Client::displayError);







    //这里关联了两个信号到自定义的槽上，当有可读的数据时会发射readyRead（）信号，当发生错误时会发射error（）信号。下面添加newConnect（）槽的定义。
}
void Client::update(qint64 s){
    if(bytesToWrite>0)
    {
        outBlock = localFile->read(qMin(bytesToWrite,payloadSize));
        qDebug() << s;
        qDebug() << "read";
        //tcpSocket->write(outBlock);
        bytesToWrite -= (int)tcpSocket->write(outBlock);
        outBlock.resize(0);
    }
    else
    {
        localFile->close();
    }
}

void Client::startTransfer(){

    fileName = "/root/image/music";
    localFile = new QFile(fileName);
    //qDebug() << localFile->exists();
    if(!localFile->open(QFile::ReadOnly)){
        qDebug() << "client:open file error";
        return;
    }
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

Client::~Client()
{}

void Client::newConnect()
{
    //初始化数据大小信息为0。
    blockSize = 0;

    //取消已有的连接。
    tcpSocket->abort();
    tcpSocket->connectToHost("localhost", 6666);
}

void Client::readMessage()
{
    QDataStream in(tcpSocket);
    //设置数据流版本，这里要和服务器端相同。
    in.setVersion(QDataStream::Qt_5_10);

    //如果这是刚开始接受数据
    if(blockSize==0){
        //判断接收数据是否大于两字节，也就是文件的大小信息所占的空间
        //如果时则保存到blockSize变量中，否则直接返回，继续接受数据
        if(tcpSocket->bytesAvailable()<(int)sizeof(quint32)) return;
        in >> blockSize;
        }
    //如果没有得到全部的数据，则返回，继续接收数据
    if(tcpSocket->bytesAvailable()<blockSize) return;
    //将接收到的数据存放到变量中
    in >> message ;
//    QMessageBox::information(this,message, "登陆成功");
//    QMessageBox::information(this,message1, "登陆成功");
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
    }
    blockSize = 0;
   // qDebug()<<message1;
//    ui->messageLabel->setText(message);
}

void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<tcpSocket->errorString();
}
