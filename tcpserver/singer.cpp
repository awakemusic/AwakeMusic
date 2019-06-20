#include "singer.h"

Singer::Singer()
{

}

Singer::Singer(QString name,QString category):m_name{name},m_category{category}
{
}

void Singer::addAlbum(Album *album)
{
    _albums.push_back(album);
}

std::vector<QString> Singer::getInformation(std::vector<QString> a)
{
    a.push_back(m_name);
    a.push_back(m_category);
}
