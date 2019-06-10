#ifndef MUSIC_H
#define MUSIC_H
#include <QString>

class Music{
public:
    Music(QString name, QString singer, QString lyric, QString album, QString audiopath);
private:
    QString m_name;
    QString m_singer;
    QString m_lyric;
    QString m_album;
    QString m_audiopath;
};

#endif // MUSIC_H
