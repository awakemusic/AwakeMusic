#include "serverwidget.h"
#include "ui_serverwidget.h"

ServerWidget::ServerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    //创建QTcpServer对象
    server = new QTcpServer();

    //侦听一个端口，使得客户端可以使用这个端口访问服务器
    if(!server->listen(QHostAddress::Any,6666))
    {
       qDebug()<<server->errorString();
    }

     //如果客户端成功和服务器连接,tcpServer会自动触发 newConnection()
    connect(server,&QTcpServer::newConnection,
            [=]()
    {
        //获取客服端的连接（取出建立好的套接字）
        socket = server->nextPendingConnection();
        //获取客服端的ip地址和端口号
        QString ip = socket->peerAddress().toString();
        quint16 port = socket->peerPort();

        qDebug()<<QString("[%1:%2]连接成功").arg(ip).arg(port);
        //显示在面板上
        QString str =QString("[%1:%2]连接成功").arg(ip).arg(port);
        //ui->textEdit->setText(str);
    });
}

ServerWidget::~ServerWidget()
{
    delete ui;
}
