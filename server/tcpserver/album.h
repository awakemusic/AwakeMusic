#ifndef ALBUM_H
#define ALBUM_H

#include <QString>
#include <vector>
class Music;

class Album
{
public:
    Album();
    Album(QString name, QString startDate);
    void addMusic(Music *music);
private:
    QString m_name;
    QString m_startDate;
    std::vector<Music*> _musics;
};

#endif // ALBUM_H
