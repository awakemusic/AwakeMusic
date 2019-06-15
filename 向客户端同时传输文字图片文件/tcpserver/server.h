#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include "ui_mainwindow.h"
#include <QTcpServer>
#include <QBuffer>
class QFile;
//class QTcpServer;

namespace Ui{
class Ui_MainWindow;
}

class Server: public QMainWindow
{
public:
    explicit Server(QWidget *parent = nullptr);
    ~Server();

private slots:
    void sendMessage();
   // void acceptConnection();
    void update();
    void startTransfer();
   // void sendPicture();

private:

    QTcpServer *tcpServer;
    //QDataStream sendOut;
    QTcpSocket *tcpSocket;
    //QTcpSocket *tcpSocket1;
    QBuffer buffer;
    Ui::MainWindow *ui;
    QPixmap pix;
    qint64 bytesToWrite;
    qint64 payloadSize;
    qint64 totalBytes;

    QString fileName;
    QFile *localFile;
    QByteArray outBlock;
    QTcpSocket *clientConnection;
};

#endif // SERVER_H
