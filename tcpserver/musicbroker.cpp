#include "musicbroker.h"

MusicBroker::MusicBroker()
{
    sqltable = new Sqltable();
}

Music* MusicBroker::findByName(QString name)
{
    return sqltable->querysingle(name);
}

QString MusicBroker::findSpell(QString name)
{
    return sqltable->querysingleTransform(name);
}

std::vector<Singer*> MusicBroker::findSinger()
{
    return sqltable->querySinger();
}

std::vector<Music*> MusicBroker::findPlayList(std::vector<QString> musics)
{
    std::vector<Music*> ms;
    for(auto l:musics)
    {
        ms.push_back(sqltable->querysingle(l));
    }
    return ms;
}

std::vector<QString> MusicBroker::findAlbums(QString name)
{
    return sqltable->querySingerAlbum(name);
}

std::vector<QString> MusicBroker::findMusics(QString name)
{
    return sqltable->queryAlbumMusics(name);
}

std::vector<QString> MusicBroker::findSingers(QString category)
{
    return sqltable->querySingerCategory(category);
}


