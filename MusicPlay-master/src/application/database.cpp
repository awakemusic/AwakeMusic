#include "database.h"

bool DataBase::createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE","sqlite1");
    db.setDatabaseName("myQtDb.db");
    if(!db.open()){
        qDebug() << "无法建立连接";
        return false;
    }
    else {
        return true;
    }
}

bool DataBase::createTable()
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1");
    QSqlQuery query(db);
    bool success = query.exec("create table automobil(id int primary key,attribute varchar,"
                                             "type varchar,kind varchar,nation int,carnumber int,elevaltor int,"
                                             "distance int,oil int,temperature int)");

    if(success){
        qDebug() << QObject::tr("数据库表创建成功!\n");
        return true;
    }
    else {
        qDebug() <<QObject::tr("数据库表创建失败！\n");
        return false;
    }
}

bool DataBase::insert(QString name, QString password)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
    QSqlQuery query(db);
    query.prepare("insert into automobil values(?, ?)");
    query.bindValue(name,password);

    bool success=query.exec();
            if(!success)
            {
                QSqlError lastError = query.lastError();
                qDebug() << lastError.driverText() << QString(QObject::tr("插入失败"));
                return false;
            }
            return true;
}

//TODO 怎么查询
bool DataBase::queryAll(QString name, QString password)
{
    QSqlDatabase db = QSqlDatabase::database("sqlite1"); //建立数据库连接
        QSqlQuery query(db);
        query.exec("select * from automobil");
        QSqlRecord rec = query.record();
        qDebug() << QObject::tr("automobil表字段数：" ) << rec.count();
        return true;
}





