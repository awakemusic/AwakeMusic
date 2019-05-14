#include "locallistmodel.h"
#include <QDir>
#include <QFileInfo>
#include <QStringList>
#include <QObject>
#include "getInfo.h"

void LocalListModel::searchLocalMusic(){
    QDir dir;
    QStringList songList;
    QFileInfoList fileList;
    const char*path = MUSIC_PATH;
    QStringList fileter;

    fileter << "*.mp3";
    dir.setNameFilters(fileter);
    if(!dir.exists(path))
    {
        qDebug() << path << " :目录不存在";
    }
    else{
        dir.cd(path);
        songList = dir.entryList();
    }
    for(int i = 0; i<songList.count();i++)
    {
        //qDebug()<<songList[i];
        m_vSongName.push_back(songList[i]);
    }
    //qDebug()<< "search函数被调用";
    //qDebug()<< dir.absolutePath();
    m_songCount = songList.count();
    m_songPath = dir.filePath(m_vSongName[m_index]);
    for(int i = 0; i<songList.count();i++)
    {
        m_vSongTime.push_back(GetInFo().getMPEGTime(dir.filePath(m_vSongName[i])));
    }
    //qDebug()<< m_songPath;
}

int LocalListModel::songCount()
{
    //qDebug()<< "songCount()函数被调用";
    return m_songCount;
}

QVector<QString> LocalListModel::vSongName()
{
    return m_vSongName;
}

QString LocalListModel::songPath()
{
    return m_songPath;
}

QVector<int> LocalListModel::vSongTime()
{
    return m_vSongTime;
}

void LocalListModel::setIndex(int index)
{
    m_index = index;
}

void LocalListModel::nextSong()
{
    if(m_index <= m_songCount)
    {
        m_index = m_index + 1;
    }
    if(m_index > (m_songCount - 1))
    {
        m_index = 0;
    }
    //qDebug()<< m_index;
}

void LocalListModel::lastSong()
{
    if(m_index <=0)
    {
        m_index = m_songCount - 1;
    }
    else{
        m_index = m_index -1;
    }
}

LocalListModel::LocalListModel(QObject *parent) : QObject (parent)
{
    qDebug()<< "构造函数函数被调用";
    m_songCount = 0;
    m_vSongName = {};
    m_songPath = " ";
    m_index = 0;
    searchLocalMusic();
}

LocalListModel::~LocalListModel()
{

}




