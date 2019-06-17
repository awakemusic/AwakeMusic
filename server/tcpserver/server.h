#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include "ui_mainwindow.h"
#include <QTcpServer>
#include <QBuffer>
#include"music.h"
#include "musicbroker.h"
class QTcpServer;

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
    void receiveData();
    void acceptConnection();

private:
    QTcpServer *tcpServer;
    QTcpSocket *clientConnection;
    Music *m;
    MusicBroker *musicBroker;

    QBuffer buffer;
    Ui::MainWindow *ui;
    QPixmap pix;

    quint32 blockSize;
    QString data;

    QString message1;
    QString message2;
    QString albumFilePath;
    std::vector<QString> a;
};

#endif // SERVER_H
