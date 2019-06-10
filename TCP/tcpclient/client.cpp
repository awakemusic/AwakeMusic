#include "client.h"
#include <QtNetwork>

Client::Client(QWidget *parent)
    : ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    newConnect();
//    connect(ui->connectButton, &QPushButton::clicked,
//            this, &Client::on_connectButtion_clicked);
    connect(tcpSocket, &QIODevice::readyRead, this, &Client::readMessage);
     connect(tcpSocket, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::error),
              this, &Client::displayError);
    //这里关联了两个信号到自定义的槽上，当有可读的数据时会发射readyRead（）信号，当发生错误时会发射error（）信号。下面添加newConnect（）槽的定义。

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
        if(tcpSocket->bytesAvailable()<(int)sizeof(quint16)) return;
        in >> blockSize;
        }
    //如果没有得到全部的数据，则返回，继续接收数据
    if(tcpSocket->bytesAvailable()<blockSize) return;
    //将接收到的数据存放到变量中
    in >> message;
    //显示接收到的数据
    qDebug()<<message;
//    ui->messageLabel->setText(message);
}

void Client::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<tcpSocket->errorString();
}
