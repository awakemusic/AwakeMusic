#include "singer.h"

Singer::Singer()
{

}

Singer::Singer(QString name):m_name{name}
{
}

void Singer::addAlbum(Album *album)
{
    _albums.push_back(album);
}
