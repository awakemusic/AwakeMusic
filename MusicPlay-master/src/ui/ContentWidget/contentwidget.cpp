#include "contentwidget.h"
#include <QBitmap>
#include <QPainter>
#include "MusisLyrc/musiclyrcwidget.h"
#include "MusiSongList/musicsongslistwidget.h"
#include "MusiSongList/musicsongslists.h"
#include <QHBoxLayout>
//#include "MusiSongList/musicsongssummarizied.h"
#include <QDebug>
#include "app.h"

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
}

void Contentwidget::initForm()
{
}

void Contentwidget::initWidget()
{
//    m_songsSummarizied = new MusicSongsSummarizied(this);
    m_musicSongsLists = new MusicSongsLists(this);
    m_musicLyrcWidget = new MusicLyrcWidget(this);
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
    m_currentwidget = 0;
    this->connectMusicList(m_currentwidget);
    m_mainLayout->setContentsMargins(0,0,0,0);
    setLayout(m_mainLayout);
    m_musicLyrcWidget->hide();
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
    m_musicSongList.at(m_currentwidget)->hide();
    m_showOrHide = true;
}

void Contentwidget::slotHideLrc()
{
    m_musicLyrcWidget->hide();
    m_musicSongList.at(m_currentwidget)->show();
    m_showOrHide = false;
}

void Contentwidget::slotShowList(int row)
{
    m_musicLyrcWidget->hide();
    m_showOrHide = false;
    m_musicSongList.at(m_currentwidget)->hide();
    this->disConnectMusicList(m_currentwidget);
    m_musicSongList.at(row)->show();
    m_currentwidget = row;
    this->connectMusicList(m_currentwidget);
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
