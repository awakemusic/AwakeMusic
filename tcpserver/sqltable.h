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
#include "singer.h"
//static QString create_sql;
class Singer;
class Album;
class Sqltable{
private:
    QSqlDatabase db;
    QSqlQuery sql_query;
    QSqlQuery sql_querySinger;
    QSqlQuery sql_queryAlbum;
    QSqlQuery sql_querySpell;

public:
    Sqltable();

public:
    void insertParmeter(int id, QString name, QString singer, QString lyric, QString album, QString audiopath);
    void query();
    void deletemusic(QString name);
    void updatamusic(int id,QString name);
    Music* querysingle(QString name);
    void insertParmeterSinger(int id, QString name,QString category);
    void insertParmeterAlbum(int id, QString name, QString startDate,QString  singerName);
    void insertParmeterTransform(QString name, QString spell);
    std::vector<Singer*> querySinger();
    void queryAlbum();
    void queryTransform();
    Singer* querysingleSinger(QString name);
    Album* querysingleAlbum(QString name);
    QString querysingleTransform(QString name);
};



#endif // SQLTABLE_H
