#ifndef CLIENT_H
#define CLIENT_H

#include <QAbstractSocket>
#include <QDialog>
#include <QBuffer>

QT_BEGIN_NAMESPACE
class QTcpSocket;
class QPushButton;
QT_END_NAMESPACE

class Client : public QDialog
{
   Q_OBJECT
public:
    Client();
    void connectServer();

private slots:
    void newConnect();
    void showPicture();
    void sendData();
    void on_connectButton_clicked();
    void displayError(QAbstractSocket::SocketError);

private:
    QTcpSocket *tcpSocket;
    QString data;
    //QPushButton *sendDataButton;
    //用来存放数据的大小信息
    QBuffer buffer;
    quint32 blockSize;
    QString filename;
    QImage image;
    QPushButton *button;
};

#endif // CLIENT_H
