#ifndef CLIENT_H
#define CLIENT_H

#include <QAbstractSocket>
#include <QDialog>
#include <QBuffer>

QT_BEGIN_NAMESPACE
class QTcpSocket;
QT_END_NAMESPACE

class Client : public QDialog
{
    Q_OBJECT
public:
    Client();
    QImage getImage();

private slots:
    void newConnect();
    void showPicture();
    void displayError(QAbstractSocket::SocketError);

private:
    QTcpSocket *tcpSocket;
    //QString message;
    //用来存放数据的大小信息
    QBuffer buffer;
    quint16 blockSize;
    QImage image;
};

#endif // CLIENT_H
