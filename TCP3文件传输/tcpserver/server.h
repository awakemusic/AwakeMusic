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
   // void sendPicture();

private:
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QBuffer buffer;
    Ui::MainWindow *ui;
    QPixmap pix;
    qint64 bytesReceived;
    qint64 totalBytes;
    qint64 fileNameSize;
    QString fileName;
    QFile *localFile;
    QByteArray inBlock;
    QTcpSocket *clientConnection;
};

#endif // SERVER_H
