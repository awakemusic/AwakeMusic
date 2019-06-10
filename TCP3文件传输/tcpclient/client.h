#ifndef CLIENT_H
#define CLIENT_H

#include <QAbstractSocket>
#include <QDialog>
#include <QLineEdit>
#include "ui_mainwindow.h"
class QFile;

QT_BEGIN_NAMESPACE
class QTcpSocket;
QT_END_NAMESPACE

namespace Ui{
class Ui_MainWindow;
}

class Client : public QMainWindow
{
public:
    explicit Client(/*QWidget *parent = nullptr*/);
    ~Client();

private slots:
    void newConnect();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);
    void on_connectButtion_clicked();
    void update(qint64 s);
    void startTransfer();

private:
    QTcpSocket *tcpSocket;
    QString message;
    QString message1;
    QFile *localFile;
    qint64 totalBytes;
    qint64 payloadSize;
    qint64 bytesToWrite;
    QByteArray outBlock;
    QString fileName;
    //用来存放数据的大小信息
    quint32 blockSize;
    Ui::MainWindow *ui;
};

#endif // CLIENT_H
