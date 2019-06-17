#include "sqltable.h"

Sqltable::Sqltable()
{  

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("MusicPlayer.db");
    if(db.open()){
        qDebug() << "Database Opened";
        QString create_sql = "create table music (id int primary key, name varchar(30), singer varchar(30), lyric varchar(30), album varchar(30), audiopath varchar(30))"; //创建数据表
        //QString select_all_sql = "select * from music";

        QSqlQuery sql_query1;
        sql_query1.prepare(create_sql);
        sql_query = sql_query1;
        if(!sql_query.exec()) //查看创建表是否成功
        {
            qDebug()<<QObject::tr("Table Create failed");
            qDebug()<<sql_query.lastError();
        }
        else
        {
            qDebug()<< "Table Created" ;
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
