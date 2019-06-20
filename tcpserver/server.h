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
    void acceptFileConnection();
    void sendSinger();
    void sendPlaylist();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    QTcpServer *tcpServer;
    QTcpSocket *clientConnection;
    QTcpServer *fileServer;
    QTcpSocket *fileConnection;

    Music *m;
    MusicBroker *musicBroker;

    QBuffer buffer;
    Ui::MainWindow *ui;
    QPixmap pix;

    quint32 blockSize;
    QString data;

    QString message1;//歌名
    QString message2;//歌手
    QString message3;//
    QString message4;
    QString albumFilePath;
    std::vector<QString> a;

    QString fileName;
    QFile *localFile;
    QFile *lyricFile;
    qint32 bytesToWrite;
    qint32 payloadSize;
    qint32 totalBytes;
};

#endif // SERVER_H
