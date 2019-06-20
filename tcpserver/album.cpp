#include "album.h"

Album::Album()
{

}

Album::Album(QString name, QString startDate,QString singerName):m_name{name},m_startDate{startDate},m_singerName{singerName}
{

}

void Album::addMusic(Music *music)
{
    _musics.push_back(music);
}
