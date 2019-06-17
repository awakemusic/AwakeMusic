#include "server.h"
#include <QtNetwork>
#include <QTcpServer>
#include <QPushButton>
#include <QGridLayout>


//#include <QtDebug>

Server::Server(QWidget *parent)
    : ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpServer = new QTcpServer();
    blockSize = 0;

    qDebug() << "构造函数赋值成功！";

//    m = musicBroker->findByName("xiaochou");
//    a = m->getInformation(a);
//    qDebug() << a[0] << a[1];

    //m = s->querysingle("xiaochou");
//    a = m->getInformation(a);
//    qDebug() << a.at(0) << a.at(1) << a.at(2);
//    message1 = a.at(0);
//    message2 = a.at(1);
//    albumFilePath = a.at(2);
//    qDebug() << "构造函数赋值成功！";
    musicBroker = new MusicBroker();
    m = musicBroker->findByName();


    QPixmap(albumFilePath).save(&buffer,"JPG");
    if(!tcpServer->listen(QHostAddress::Any,6667)){
        qDebug()<<tcpServer->errorString();
        close();
    }
    // tcpServer->listen( QHostAddress::LocalHost, 6667);
    connect(tcpServer,&QTcpServer::newConnection,this,&Server::acceptConnection);
    //调用了qtcpserver类的listen（）函数来监听到来的连接，这里监听了本地主机的6666端口，这样可以实现客户端和服务端在同一台计算机上运行并通信，也可以换成其他地址。
    //一旦有客户端连接到服务器就会发射newConnection（）信号。

}


Server::~Server()
{}


void Server::acceptConnection()
{
    clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection, &QIODevice::readyRead,this,&Server::receiveData);
}

void Server::receiveData()
{
    QDataStream in(clientConnection);
    //设置数据流版本，这里要和服务器端相同。
    in.setVersion(QDataStream::Qt_5_10);

    if(blockSize==0){
        //判断接收数据是否大于两字节，也就是文件的大小信息所占的空间
        //如果时则保存到blockSize变量中，否则直接返回，继续接受数据
        if(clientConnection->bytesAvailable() < (int)sizeof(quint32)) return;
        in >> blockSize;
    }
    //如果没有得到全部的数据，则返回，继续接收数据
    if(clientConnection->bytesAvailable()<blockSize) return;
    //将接收到的数据存放到变量中
    in >> data;
    qDebug()<<data;

    if(!data.isNull())
    {

        sendMessage();
    }
    blockSize = 0;
    //显示接收到的数据
}

void Server::sendMessage()
{
    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);

    out.setVersion(QDataStream::Qt_5_10);
    message1 = a.at(0);
    message2 = a.at(1);

    out << quint32(message1.size() +message2.size()+ buffer.data().size());
    out << message1 << message2;

    block.append(buffer.data());

    connect(clientConnection, &QAbstractSocket::disconnected,
            clientConnection, &QObject::deleteLater);

    clientConnection->write(block);

    block.resize(0);

    clientConnection->disconnectFromHost();
    ui->label->setText("send message successful!!!");
}
