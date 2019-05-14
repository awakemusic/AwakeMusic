#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include "locallistmodel.h"
#include "clientwidget.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    //QGuiApplication app(argc, argv);
    QApplication app(argc,argv);
    ClientWidget w;

    qmlRegisterType<LocalListModel>("LocalListModel",1,0,"LocalListModel");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
