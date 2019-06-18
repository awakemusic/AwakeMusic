#include "sqltable.h"
#include "singer.h"
#include "album.h"

Sqltable::Sqltable()
{  

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MusicPlayer.db");
    if(db.open()){
        qDebug() << "Database Opened";
        QString create_sql = "create table music (id int primary key, name varchar(30), singer varchar(30), lyric varchar(30), album varchar(30), audiopath varchar(30))"; //创建数据表
        //QString select_all_sql = "select * from music";
        QString create_sql1 = "create table singer (id int primary key, name varchar(30))"; //创建数据表
        QString create_sql2 = "create table album (id int primary key, name varchar(30), startTime varchar(30))"; //创建数据表

        QSqlQuery sql_query1,sql_query2,sql_query3;
        sql_query1.prepare(create_sql);
        sql_query2.prepare(create_sql1);
        sql_query3.prepare(create_sql2);
        sql_query = sql_query1;
        sql_querySinger = sql_query2;
        sql_queryAlbum = sql_query3;
        if(!sql_query.exec()) //查看创建表是否成功
        {
            qDebug()<<QObject::tr("Table Create failed");
            qDebug()<<sql_query.lastError();
        }
        if(!sql_querySinger.exec()) //查看创建表是否成功
        {
            qDebug()<<QObject::tr("Table Create failed");
            qDebug()<<sql_querySinger.lastError();
        }
        if(!sql_queryAlbum.exec()) //查看创建表是否成功
        {
            qDebug()<<QObject::tr("Table Create failed");
            qDebug()<<sql_queryAlbum.lastError();
        }
        else
        {
            qDebug()<< "Tables Created" ;
        }
    }


}


void Sqltable::insertParmeter(int id, QString name, QString singer, QString lyric, QString album, QString audiopath)
{
    db.open();
    //QSqlQuery sql_query;
    QString insert_sql = "insert into music values(?,?,?,?,?,?)";    //插入数据


    //插入数据
    sql_query.prepare(insert_sql);


    sql_query.addBindValue(id);
    sql_query.addBindValue(name);
    sql_query.addBindValue(singer);
    sql_query.addBindValue(lyric);
    sql_query.addBindValue(album);
    sql_query.addBindValue(audiopath);
    if(!sql_query.execBatch())
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        qDebug()<<"插入记录成功";
    }
    if(!sql_query.exec())
    {
        qDebug()<<sql_query.lastError();
    }

    db.close();
}


void Sqltable::insertParmeterSinger(int id, QString name)
{
    db.open();
    //QSqlQuery sql_query;
    QString insert_sql = "insert into singer values(?,?)";    //插入数据


    //插入数据
    sql_querySinger.prepare(insert_sql);


    sql_querySinger.addBindValue(id);
    sql_querySinger.addBindValue(name);

    if(!sql_querySinger.execBatch())
    {
        qDebug()<<sql_querySinger.lastError();
    }
    else
    {
        qDebug()<<"插入记录成功";
    }
    if(!sql_querySinger.exec())
    {
        qDebug()<<sql_querySinger.lastError();
    }

    db.close();
}

void Sqltable::insertParmeterAlbum(int id, QString name, QString startTime)
{
    db.open();
    //QSqlQuery sql_query;
    QString insert_sql = "insert into music values(?,?,?)";    //插入数据


    //插入数据
    sql_queryAlbum.prepare(insert_sql);


    sql_queryAlbum.addBindValue(id);
    sql_queryAlbum.addBindValue(name);
    sql_queryAlbum.addBindValue(startTime);

    if(!sql_queryAlbum.execBatch())
    {
        qDebug()<<sql_queryAlbum.lastError();
    }
    else
    {
        qDebug()<<"插入记录成功";
    }
    if(!sql_queryAlbum.exec())
    {
        qDebug()<<sql_queryAlbum.lastError();
    }

    db.close();
}

void Sqltable::querySinger()
{
    QString select_all_sql = "select * from singer";
    //QSqlQuery sql_query1;
    db.open();
    //QSqlQuery sql_query;
    sql_querySinger.prepare(select_all_sql);
    //sql_query = sql_query1;

    if(!sql_querySinger.exec())
    {
        qDebug()<<sql_querySinger.lastError();
    }
    else
    {
        qDebug()<<"查询成功" ;
        while(sql_querySinger.next())
        {
            int id = sql_querySinger.value(0).toInt();
            QString name = sql_querySinger.value(1).toString();

            qDebug()<<"checked";
            qDebug()<<QString("ID:%1  Name:%2 " ).arg(id).arg(name);
        }
    }
    db.close();
}

void Sqltable::queryAlbum()
{
    QString select_all_sql = "select * from album";
    //QSqlQuery sql_query1;
    db.open();
    //QSqlQuery sql_query;
    sql_queryAlbum.prepare(select_all_sql);
    //sql_query = sql_query1;

    if(!sql_queryAlbum.exec())
    {
        qDebug()<<sql_queryAlbum.lastError();
    }
    else
    {
        qDebug()<<"查询成功" ;
        while(sql_queryAlbum.next())
        {
            int id = sql_queryAlbum.value(0).toInt();
            QString name = sql_queryAlbum.value(1).toString();
            QString startTime = sql_queryAlbum.value(2).toString();
            qDebug()<<"checked";
            qDebug()<<QString("ID:%1  Name:%2  starDate:%3 " ).arg(id).arg(name).arg(startTime);
        }
    }
    db.close();
}

void Sqltable::query()
{
    QString select_all_sql = "select * from music";
    //QSqlQuery sql_query1;
    db.open();
    //QSqlQuery sql_query;
    sql_query.prepare(select_all_sql);
    //sql_query = sql_query1;

    if(!sql_query.exec())
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        qDebug()<<"查询成功" ;
        while(sql_query.next())
        {
            int id = sql_query.value(0).toInt();
            QString name = sql_query.value(1).toString();
            QString singer = sql_query.value(2).toString();
            QString lyric = sql_query.value(3).toString();
            QString album = sql_query.value(4).toString();
            QString audiopath = sql_query.value(5).toString();
            qDebug()<<"checked";
            qDebug()<<QString("ID:%1  Name:%2  singer:%3 lyric:%4 album:%5 audiopath:%6" ).arg(id).arg(name).arg(singer).arg(lyric).arg(album).arg(audiopath);
        }
    }
    db.close();
}


void Sqltable::deletemusic(QString name)
{
    db.open();
    QString delete_sql = "delete from music where name = ?";
    sql_query.prepare(delete_sql);
    sql_query.addBindValue(name);
    if(!sql_query.exec())
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        qDebug()<<"删除成功" ;

    }
    db.close();
}


void Sqltable::updatamusic(int id,QString name)
{
    db.open();
    QString update_sql = "update music set name = :name where id = :id";
    sql_query.prepare(update_sql);
    sql_query.bindValue(":name",name);
    sql_query.bindValue(":id",id);
    if(!sql_query.exec())
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        qDebug()<<"更新成功" ;

    }
    db.close();
}


Music* Sqltable::querysingle(QString name)
{
    Music *music;
    db.open();
    QString select_sql = "select * from music where name = '" + name +"'";
    sql_query.prepare(select_sql);
    //sql_query.addBindValue(name);
    if(!sql_query.exec())
    {
        qDebug()<<sql_query.lastError();
    }
    else
    {
        qDebug()<<"查询成功" ;
        while(sql_query.next())
        {

            int id = sql_query.value(0).toInt();
            QString name1 = sql_query.value(1).toString();
            //qDebug() << QString("%1").arg(name1);
            QString singer = sql_query.value(2).toString();
            QString lyric = sql_query.value(3).toString();
            QString album = sql_query.value(4).toString();
            QString audiopath = sql_query.value(5).toString();
            music = new Music(name1,singer,lyric,album,audiopath);

            qDebug()<<"checked";
            qDebug()<<QString("ID:%1  Name:%2  singer:%3 lyric:%4 album:%5 audiopath:%6" ).arg(id).arg(name1).arg(singer).arg(lyric).arg(album).arg(audiopath);
        }
    }
    db.close();

    return music;
}

Singer* Sqltable::querysingleSinger(QString name)
{
    Singer *singer;
    db.open();
    QString select_sql = "select * from singer where name = '" + name +"'";
    sql_querySinger.prepare(select_sql);
    //sql_query.addBindValue(name);
    if(!sql_querySinger.exec())
    {
        qDebug()<<sql_querySinger.lastError();
    }
    else
    {
        qDebug()<<"查询成功" ;
        while(sql_querySinger.next())
        {

            int id = sql_querySinger.value(0).toInt();
            QString name1 = sql_querySinger.value(1).toString();

            singer = new Singer(name1);

            qDebug()<<"checked";
            qDebug()<<QString("ID:%1  Name:%2 " ).arg(id).arg(name1);
        }
    }
    db.close();

    return singer;
}

Album* Sqltable::querysingleAlbum(QString name)
{
    Album *album;
    db.open();
    QString select_sql = "select * from album where name = '" + name +"'";
    sql_queryAlbum.prepare(select_sql);
    //sql_query.addBindValue(name);
    if(!sql_queryAlbum.exec())
    {
        qDebug()<<sql_queryAlbum.lastError();
    }
    else
    {
        qDebug()<<"查询成功" ;
        while(sql_queryAlbum.next())
        {

            int id = sql_queryAlbum.value(0).toInt();
            QString name1 = sql_queryAlbum.value(1).toString();
            QString startDate = sql_queryAlbum.value(2).toString();

            album = new Album(name1,startDate);

            qDebug()<<"checked";
            qDebug()<<QString("ID:%1  Name:%2 startDate:%3" ).arg(id).arg(name1).arg(startDate);
        }
    }
    db.close();

    return album;
}