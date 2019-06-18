#ifndef SINGER_H
#define SINGER_H
#include<QString>
#include<vector>

class Album;

class Singer
{
public:
    Singer();
    Singer(QString name);
    void addAlbum(Album *album);

private:
    QString m_name;
    std::vector<Album*> _albums;
};

#endif // SINGER_H
