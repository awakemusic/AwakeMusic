#include "musicbroker.h"

MusicBroker::MusicBroker()
{
    sqltable = new Sqltable();
}

Music* MusicBroker::findByName(QString name)
{
    return sqltable->querysingle(name);
}
