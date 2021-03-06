﻿#include "contentwidget.h"
#include <QBitmap>
#include <QPainter>
#include "MusisLyrc/musiclyrcwidget.h"
#include "MusiSongList/musicsongslistwidget.h"
#include "MusiSongList/musicsongslists.h"
#include <QHBoxLayout>
//#include "MusiSongList/musicsongssummarizied.h"
#include <QDebug>
#include "app.h"
#include "MusiSongList/musicsongsmedia.h"

Contentwidget::Contentwidget(QWidget *parent) :
    QWidget(parent)
{
    initForm();
    initWidget();
    initLayout();
    initConnect();
}

Contentwidget::~Contentwidget()
{
    //    delete m_songsSummarizied;
    delete m_musicSongsLists;
    delete m_musicLyrcWidget;
    //    delete m_musicSongList;
    while (!m_musicSongList.isEmpty()) {
        MusicSongsListWidget *w = m_musicSongList.takeLast();
        delete w;
        w = NULL;
    }
    delete m_musicSongsMedia;
    delete m_musicSongsMedia2;
}

void Contentwidget::initForm()
{
}

void Contentwidget::initWidget()
{
    //    m_songsSummarizied = new MusicSongsSummarizied(this);
    m_musicSongsLists = new MusicSongsLists(this);
    m_musicLyrcWidget = new MusicLyrcWidget(this);
    m_musicSongsMedia = new MusicSongsMedia(this);
    m_musicSongsMedia2 = new MusicSongsMedia(this);
    MusicSongsListWidget *widget = new MusicSongsListWidget(this);
    m_musicSongList.append(widget);
    widget->addMusicFold("/root/CloudMusic/");
}

void Contentwidget::initLayout()
{
    m_mainLayout = new QHBoxLayout(this);
    //    m_mainLayout->addWidget(m_songsSummarizied,Qt::AlignLeft);
    m_mainLayout->addWidget(m_musicSongsLists,Qt::AlignLeft);
    m_mainLayout->addWidget(m_musicLyrcWidget,Qt::AlignRight);
    m_mainLayout->addWidget(m_musicSongList.at(0),Qt::AlignRight);
    m_mainLayout->addWidget(m_musicSongsMedia,Qt::AlignRight);
    m_mainLayout->addWidget(m_musicSongsMedia2,Qt::AlignRight);
    m_currentwidget = 0;
    this->connectMusicList(m_currentwidget);
    m_mainLayout->setContentsMargins(0,0,0,0);
    setLayout(m_mainLayout);
    m_musicLyrcWidget->hide();
    m_musicSongsMedia->hide();
    m_musicSongsMedia2->hide();
    m_showOrHide = false;
}

void Contentwidget::initConnect()
{
    /*****************接收当前播放的音乐，解析歌词****************/
    connect(this,SIGNAL(signalRequestPlayingMusic(QString)),
            m_musicLyrcWidget,SLOT(slotReceiveMusicInfo(QString)));
    connect(this,SIGNAL(signalRequestCurPlayTime(qint64)),
            m_musicLyrcWidget,SLOT(slotReceiveCurrentPlayTime(qint64)));
    connect(m_musicLyrcWidget,SIGNAL(signalHideLrc()),
            this,SLOT(slotHideLrc()));
    /***************根据点击的列表显示列表内容**********************/
    connect(m_musicSongsLists,SIGNAL(signalShowList(int)),
            this,SLOT(slotShowList(int)));
    connect(m_musicSongsLists,SIGNAL(signalAddNewList()),
            this,SLOT(slotAddNewList()));
    connect(m_musicSongsLists,SIGNAL(signalDeleteList(int)),
            this,SLOT(slotDeleteList(int)));
    connect(m_musicSongsMedia,SIGNAL(signalPlayMediaMusic(QString)),
            this,SIGNAL(signalPlayMediaMusic(QString)));
    /***************显示客户端传输数据**********************/
    connect(this,SIGNAL(signalShowInfo(QString,QString,QString)),
            m_musicSongsMedia,SLOT(slotAddItem(QString,QString,QString)));
    connect(this,SIGNAL(signalSendPinYin(QString,QString)),
            m_musicSongsMedia,SLOT(slotSaveMusicInfo(QString,QString)));
    connect(m_musicSongsMedia,SIGNAL(signalShowMediaLrc(QString)),
            m_musicLyrcWidget,SLOT(slotAnalyseMedia(QString)));

    connect(m_musicSongsMedia2,SIGNAL(signalPlayMediaMusic(QString)),
            this,SIGNAL(signalPlayMediaMusic(QString)));
    connect(m_musicSongsMedia2,SIGNAL(signalShowMediaLrc(QString)),
            m_musicLyrcWidget,SLOT(slotAnalyseMedia(QString)));
//    connect(this,SIGNAL(signalShowInfo(QString,QString,QString)),
//            m_musicSongsMedia2,SLOT(slotAddItem(QString,QString,QString)));
//    connect(this,SIGNAL(signalSendPinYin(QString,QString)),
//            m_musicSongsMedia2,SLOT(slotSaveMusicInfo(QString,QString)));
}

void Contentwidget::connectMusicList(int index)
{
    connect(this,SIGNAL(signalRequestFirstPlayMusic()),
            m_musicSongList.at(index),SLOT(slotGetFirstPlayMusic()));
    connect(m_musicSongList.at(index),SIGNAL(signalSendFirstPlayMusic(QString)),
            this,SIGNAL(signalSendFirstPlayMusic(QString)));
    connect(this,SIGNAL(signalSendPlayPreviouse()),
            m_musicSongList.at(m_currentwidget),SLOT(slotGetPreviouseMusic()));
    connect(this,SIGNAL(signalSendPlayNext()),
            m_musicSongList.at(m_currentwidget),SLOT(slotGetNextMusic()));
    connect(m_musicSongList.at(m_currentwidget),SIGNAL(signalSendPreviousMusic(QString)),
            this,SIGNAL(signalSendPlayPreviouseMusic(QString)));
    connect(m_musicSongList.at(m_currentwidget),SIGNAL(signalSendNextMusic(QString)),
            this,SIGNAL(signalSendPlayNextMusic(QString)));
    connect(m_musicSongList.at(m_currentwidget),SIGNAL(signalPlayMusicPath(QString)),
            this,SIGNAL(signalPlayMusic(QString)));
    connect(m_musicSongList.at(m_currentwidget),SIGNAL(signalShowLyric()),
            this,SLOT(slotShowLrc()));
    connect(this,SIGNAL(signalRequestPlayCmd(int)),
            m_musicSongList.at(m_currentwidget),SLOT(slotSendPlayCmd(int)));
    connect(m_musicSongList.at(m_currentwidget),SIGNAL(signalSendPlayCmdMusicInfo(QString)),
            this,SIGNAL(signalSendPlayCmdMusic(QString)));
}

void Contentwidget::disConnectMusicList(int index)
{
    disconnect(this,SIGNAL(signalRequestFirstPlayMusic()),
               m_musicSongList.at(index),SLOT(slotGetFirstPlayMusic()));
    disconnect(m_musicSongList.at(index),SIGNAL(signalSendFirstPlayMusic(QString)),
               this,SIGNAL(signalSendFirstPlayMusic(QString)));
    disconnect(this,SIGNAL(signalSendPlayPreviouse()),
               m_musicSongList.at(m_currentwidget),SLOT(slotGetPreviouseMusic()));
    disconnect(this,SIGNAL(signalSendPlayNext()),
               m_musicSongList.at(m_currentwidget),SLOT(slotGetNextMusic()));
    disconnect(m_musicSongList.at(m_currentwidget),SIGNAL(signalSendPreviousMusic(QString)),
               this,SIGNAL(signalSendPlayPreviouseMusic(QString)));
    disconnect(m_musicSongList.at(m_currentwidget),SIGNAL(signalSendNextMusic(QString)),
               this,SIGNAL(signalSendPlayNextMusic(QString)));
    disconnect(m_musicSongList.at(m_currentwidget),SIGNAL(signalPlayMusicPath(QString)),
               this,SIGNAL(signalPlayMusic(QString)));
    disconnect(m_musicSongList.at(m_currentwidget),SIGNAL(signalShowLyric()),
               this,SLOT(slotShowLrc()));
    disconnect(this,SIGNAL(signalRequestPlayCmd(int)),
               m_musicSongList.at(m_currentwidget),SLOT(slotSendPlayCmd(int)));
    disconnect(m_musicSongList.at(m_currentwidget),SIGNAL(signalSendPlayCmdMusicInfo(QString)),
               this,SIGNAL(signalSendPlayCmdMusic(QString)));
}


void Contentwidget::slotReceiveFirstPlayMusic(int cmd)
{
    //发送之前先检测当前是否正在播放音乐
    App::ReadConfig();
    if (!App::IsPlaying)
    {
        if (MUSIC_PLAY == cmd)
        {
            emit signalRequestFirstPlayMusic();
        }
    }

}

void Contentwidget::slotShowLrc()
{
    m_musicLyrcWidget->show();
    m_musicSongsMedia->hide();
    m_musicSongsMedia2->hide();
    m_musicSongList.at(m_currentwidget)->hide();
    m_showOrHide = true;
}

void Contentwidget::slotHideLrc()
{
    m_musicLyrcWidget->hide();
    m_musicSongsMedia2->hide();
    m_musicSongList.at(m_currentwidget)->show();
    m_showOrHide = false;
}

void Contentwidget::slotShowList(int row)
{
    m_musicLyrcWidget->hide();
    m_showOrHide = false;
    m_musicSongList.at(m_currentwidget)->hide();
    this->disConnectMusicList(m_currentwidget);
    if(row == 1){
        m_musicSongsMedia2->show();
    }else{
        m_musicSongsMedia2->hide();
        if(row == 0){
            m_musicSongList.at(row)->show();
            m_currentwidget = row;
            this->connectMusicList(m_currentwidget);
        }
        else{
            m_musicSongList.at(row-1)->show();
            m_currentwidget = row-1;
            this->connectMusicList(m_currentwidget-1);
        }
    }
    m_musicSongsMedia->hide();
}

void Contentwidget::slotAddNewList()
{
    MusicSongsListWidget *widget = new MusicSongsListWidget(this);
    m_musicSongList.append(widget);
    m_mainLayout->addWidget(widget,Qt::AlignRight);
    widget->hide();
    initConnect();
}

void Contentwidget::slotDeleteList(int row)
{
    m_musicSongList.removeAt(row);
}

void Contentwidget::slotShowOrHide()
{
    if(m_showOrHide)
        slotHideLrc();
    else
        slotShowLrc();
}

void Contentwidget::slotShowMediaSongs()
{
    m_musicSongsMedia->removeAllItem();
    m_musicSongsMedia->show();
    m_musicSongList.at(m_currentwidget)->hide();
    m_musicLyrcWidget->hide();
    m_musicSongsMedia2->hide();
    m_showOrHide = false;
}

//重绘事件
void Contentwidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen objPen(Qt::transparent);
    painter.setPen(objPen);
    QBrush objBrush(QColor(255,255,255,120));
    painter.setBrush(objBrush);
    painter.drawRect(this->rect());
}
