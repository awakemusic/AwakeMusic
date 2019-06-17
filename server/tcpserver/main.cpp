#include "mainwindow.h"
#include "server.h"
#include "sqltable.h"
#include "music.h"
#include "musicbroker.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server *server = new Server;
    server->show();
    Sqltable *sqltable = new Sqltable();
    sqltable->query();
//    Music *music;
//    music = sqltable->querysingle("xiaochou");

//    s = music->getInformation(s);
//    qDebug() << s.at(0) << s.at(1) << s.at(2);
    //sqltable->insertParmeter(0,"xiaochou","maobuyi","lyric","/root/album.jpg","/root");
//    Music *m = new Music();
//    MusicBroker *broker = new MusicBroker();
//    m = broker->findByName();
//    s = m->getInformation(s);
//    qDebug() << s.at(0) << s.at(1) << s.at(2);
//    qDebug() << "赋值成功！";

    return a.exec();
}
