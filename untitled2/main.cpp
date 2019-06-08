#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "qvlcplayer.h"
#include "vlc/vlc.h"
#include "vlc/libvlc_media.h"
#include <QTextCodec>
QString UnicodeToUTF8(const QString &strWide)
{
    QString strUtf8;
    QStringList t;
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    for (int i = 0; i <strWide.length(); i+=4)
    {
        t.append(strWide.mid(i,4));
    }
    foreach (const QString &str, t) {
        strUtf8.append(str);
    }

    return codec->fromUnicode(strUtf8);
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QString filePath;
    filePath = "rtsp://192.168.30.145/song.mp3";
    filePath = UnicodeToUTF8(filePath);
    libvlc_media_t *m;
    libvlc_instance_t     *m_pVLC_Inst;
    m_pVLC_Inst = libvlc_new(0,NULL);

    //m = libvlc_media_new_path(m_pVLC_Inst,m_filePath.toLatin1()/*toAscii()*/);
    m = libvlc_media_new_location(m_pVLC_Inst,filePath.toLatin1()/*toAscii()*/);
    libvlc_media_player_t *m_pVLC_Player;
    if (m)
    {
        m_pVLC_Player = libvlc_media_player_new_from_media(m);
        if (m_pVLC_Player)
        {
            libvlc_media_player_play(m_pVLC_Player);
        }
    }
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/register.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
