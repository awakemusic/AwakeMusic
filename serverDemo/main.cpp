#include "mainwindow.h"
#include <QApplication>
#include "sqltable.h"
#include "text.h"
#include<iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    w.show();
    Sqltable *s = new Sqltable();
    //std::cout <<" hello!"<< std::endl;
    s->insertParmeter(0,"小丑","毛布已","34","56","78");
    s->insertParmeter(1,"xiao","haha","3","5","7");
    s->query();
    s->deletemusic("小丑");
    s->query();
    s->updatamusic(1,"消愁");
    s->query();
    s->querysingle("消愁");
    //createtable();
    return a.exec();
}
