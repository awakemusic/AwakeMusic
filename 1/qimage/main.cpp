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
    QLabel* label=new QLabel("",0);
    QImage image;
    image.load("/root/album.jpg");
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(image));

    label->setMinimumSize(label->width(), label->height());
    label->setMaximumSize(label->width(), label->height());
    label->setScaledContents(true);

    label->setPalette(palette);
    label->show();
    //QImage image;

    //image.load(client->getImage());

    //        if (engine.rootObjects().isEmpty())
    //            return -1;
    return app.exec();
}
