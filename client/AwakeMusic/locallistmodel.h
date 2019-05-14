#ifndef LOCALLISTMODEL_H
#define LOCALLISTMODEL_H

#include <QDir>
#include <QString>
#include <QObject>
#include <QVector>
#include <QDebug>

/*#ifdef Q_OS_WIN
    #define MUSIC_PATH "../QtMusic/localMusic"
    #define MUSIC_LYRIC_PATH "d:/KuGou/Lyric"
#elif
    #define MUSIC_PATH "../QtMusic/localMusic"
#endif*/
    #define MUSIC_PATH "../QtMusic/localMusic"

class LocalListModel : public QObject
{
    Q_OBJECT
    //用于qml的属性
public:
    Q_PROPERTY(int songCount READ songCount)
    Q_PROPERTY(QVector<QString> vSongName READ vSongName)
    Q_PROPERTY(QString songPath READ songPath)
    Q_PROPERTY(QVector<int> vSongTime READ vSongTime) //获取歌曲时间


public:
    Q_INVOKABLE void searchLocalMusic();
    Q_INVOKABLE void nextSong();
    Q_INVOKABLE void lastSong();

    int songCount();
    QVector<QString> vSongName();
    QString songPath();
    QVector<int> vSongTime();

protected:
    LocalListModel(QObject* parent = nullptr);
    ~LocalListModel();
private:
    int m_songCount;
    QVector<QString> m_vSongName;
    QString m_songPath;
    int m_index;
    QVector<int> m_vSongTime;


public slots:
    void setIndex(int index);

signals:
    void songPathChanged();
};

#endif // LOCALLISTMODEL_H
