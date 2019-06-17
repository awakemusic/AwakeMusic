#include "mainwindow.h"
#include "server.h"
#include "sqltable.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server *server = new Server;
    server->show();
    Sqltable *sqltable = new Sqltable();
    //sqltable->insertParmeter(0,"xiaochou","maobuyi","root","album","/root");
    sqltable->query();

    return a.exec();
}
