#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include "ui_mainwindow.h"
#include <QTcpServer>
#include <QBuffer>

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
   // void sendPicture();

private:
    QTcpServer *tcpServer;
    QBuffer buffer;
    Ui::MainWindow *ui;
    QPixmap pix;
};

#endif // SERVER_H
