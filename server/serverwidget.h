#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class ServerWidget;
}

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();

private:
    Ui::ServerWidget *ui;
    QTcpServer *server;
    QTcpSocket *socket;
};

#endif // SERVERWIDGET_H
