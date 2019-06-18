#include "album.h"

Album::Album()
{

}

Album::Album(QString name, QString startDate):m_name{name},m_startDate{startDate}
{

}

void Album::addMusic(Music *music)
{
    _musics.push_back(music);
}
