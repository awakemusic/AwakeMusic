#ifndef MUSICBROKER_H
#define MUSICBROKER_H

#include <vector>
#include "sqltable.h"
#include "music.h"

class MusicBroker
{
public:
    MusicBroker();
    Music* findByName(QString name);
    //Music findBySinger(QString singer);

private:
    Sqltable *sqltable;
    std::vector<Music*> m_musics;
};

#endif // MUSICBROKER_H
