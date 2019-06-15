#include <QGuiApplication>
#include <QApplication>
#include <QLabel>
#include <QPixmap>
#include <QPalette>
#include "client.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);
    Client *client = new Client;
    client->show();
    return app.exec();
}
