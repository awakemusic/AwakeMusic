#ifndef SQLTABLE_H
#define SQLTABLE_H
#include <QCoreApplication>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QVariantList>
#include "music.h"
//static QString create_sql;
class Singer;
class Album;
class Sqltable{
private:
    QSqlDatabase db;
    QSqlQuery sql_query;
    QSqlQuery sql_querySinger;
    QSqlQuery sql_queryAlbum;

public:
    Sqltable();

public:
    void insertParmeter(int id, QString name, QString singer, QString lyric, QString album, QString audiopath);
    void query();
    void deletemusic(QString name);
    void updatamusic(int id,QString name);
    Music* querysingle(QString name);
    void insertParmeterSinger(int id, QString name);
    void insertParmeterAlbum(int id, QString name, QString startTime);
    void querySinger();
    void queryAlbum();
    Singer* querysingleSinger(QString name);
    Album* querysingleAlbum(QString name);
};



#endif // SQLTABLE_H
