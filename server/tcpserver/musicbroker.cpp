#include "musicbroker.h"

MusicBroker::MusicBroker()
{

}

Music* MusicBroker::findByName()
{
    return sqltable->querysingle("xiaochou");

}
