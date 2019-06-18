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

public slots:
    void newConnect();
    void showString();
    void sendData(QString data);
    void displayError(QAbstractSocket::SocketError);

Q_SIGNALS:
    void signalShowImage(QImage image);
private:
    QTcpSocket *tcpSocket;
    QString data;
    //QPushButton *sendDataButton;
    //用来存放数据的大小信息
    QBuffer buffer;
    quint32 blockSize;
    QString filename;
    QImage image;
//    QPushButton *button;
};

#endif // CLIENT_H
