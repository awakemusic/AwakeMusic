#ifndef CLIENT_H
#define CLIENT_H

#include <QAbstractSocket>
#include <QDialog>
#include <QLineEdit>
#include "ui_mainwindow.h"

QT_BEGIN_NAMESPACE
class QTcpSocket;
QT_END_NAMESPACE

namespace Ui{
class Ui_MainWindow;
}

class Client : public QMainWindow
{
public:
    explicit Client(QWidget *parent = nullptr);
    ~Client();

private slots:
    void newConnect();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);
    void on_connectButtion_clicked();

private:
    QTcpSocket *tcpSocket;
    QString message;
    //用来存放数据的大小信息
    quint16 blockSize;
    Ui::MainWindow *ui;
};

#endif // CLIENT_H
