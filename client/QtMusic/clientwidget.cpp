#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    //建立客服端套接字对象
    socket = new QTcpSocket();

    //连接服务器
    socket->connectToHost("127.0.0.1",6666);
}

ClientWidget::~ClientWidget()
{
    delete ui;
}
