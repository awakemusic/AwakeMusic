﻿#include "musicsongslistwidget.h"
#include "musiclistmenu.h"
#include <QContextMenuEvent>
#include <QHeaderView>
#include <QDebug>
#include <QVBoxLayout>
#include <QFileDialog>
#include "controlvalues.h"
#include "client.h"
#include "myhelper.h"

MusicSongsListWidget::MusicSongsListWidget(QWidget *parent)
    :QTableWidget(parent)
{
    initForm();
    initConnect();
}

MusicSongsListWidget::~MusicSongsListWidget()
{
    delete m_menu;
}

/*向表格中添加数据
 * 输入参数：要添加的你内容，行，列(默认列为0)
 */
void MusicSongsListWidget::addItemContent(QString content)
{
    QTableWidgetItem *item = new QTableWidgetItem (content);
    item->setTextAlignment(Qt::AlignLeft |Qt::AlignVCenter);
    int rowIndex = rowCount();
    if (rowIndex >= 0)
    {
        //总函数加1
        setRowCount(rowIndex + 1);
        //添加一条记录到表格中来
        setItem(rowIndex,0,item);
    }
}

//删除当前行,若当前没有选中任何行，currentRow()返回-1
void MusicSongsListWidget::removeItem()
{
    int rowIndex = currentRow();
    if (rowIndex != -1)
    {
        removeRow(rowIndex);
    }
}

//删除所有的歌曲
void MusicSongsListWidget::removeAllItem()
{
    //获取本列表的行数
    //    int len = rowCount();

    //    for (int i = 0; i < len; i++)
    //    {
    //        removeRow(i);
    //    }

    /*采用循环方式进行删除时出现删除不完整问题，采用以下方法可以解决问题*/

    setRowCount(0);
    clearContents();
}

/*获取当前鼠标点击的行的内容，便于进行播放音乐
 * 说明：2016-3-16 20:56:29 修改bug，对当前列表为空进行判断处理
*/
QString MusicSongsListWidget::getSelectContent()
{
    QString content = "";
    if (tableWidgetIsEmpty())
    {
#if QDEBUG_OUT
        qDebug()<<"当前列表为空!";
#endif
        return content;
    }else{
        int row = currentItem()->row();
        content = item(row,0)->text();
    }
    return content;
}

void MusicSongsListWidget::addMusicFold(QString path)
{
    int i = 0;
    QDir dir(path);
    QStringList stringlist_song;//用来保存歌曲名的表
    QFileInfoList fileinfolist;//文件信息表
    QFileInfo fileinfo;//文件信息变量
    QString string_song;//用于保存文件信息字符串

    stringlist_song << "*.mp3";//把所有mp3文件加入到stringlist_song表中
    dir.setNameFilters(stringlist_song);//过滤文件
    fileinfolist = dir.entryInfoList();//列出所有符合的文件
    stringlist_song.clear();
    while( i<fileinfolist.length() ){
        fileinfo = fileinfolist.at(i);
        string_song = fileinfo.filePath();//把fileinfo变量中的文件名转换成QString并赋给string_song
        stringlist_song << string_song;//把歌曲名赋给stringlist_song表
        i++;
    }
    importMusicSongsName(stringlist_song);
}

//保存歌曲信息
void MusicSongsListWidget::saveMusicInfo(const QString &name, const QString &path)
{
    m_musicInfo[name] = path;
}

//获取歌曲路径
QString MusicSongsListWidget::getMusicPath(const QString &name)
{
    return m_musicInfo.value(name);
}

bool MusicSongsListWidget::tableWidgetIsEmpty()
{
    if (rowCount() > 0)
        return false;
    return true;
}

void MusicSongsListWidget::importMusicSongsName(const QStringList &file_name_list)
{
    //获取当前列表索引
//    int index = currentIndex();
    QFileInfo finfo;
    QStringList fileNameList;
    QStringList filePath;

    if (file_name_list.isEmpty())
    {
        return;
    }
    //提取出歌曲名称
    foreach (QString str, file_name_list) {
        finfo = QFileInfo(str);
        fileNameList <<finfo.fileName();
        filePath << finfo.filePath();
    }

    //插入多条歌曲到列表中
    for (int i = 0; i <fileNameList.count(); i++)
    {
        //将歌曲名称插入到列表中
        this->addItemContent(fileNameList.at(i));
        //保存歌曲信息，以便进行歌曲播放
        this->saveMusicInfo(fileNameList.at(i),filePath.at(i));
    }
}

//获取鼠标双击单元格内容
void MusicSongsListWidget::slotCellDoubleClicked(int row, int column)
{
    QString songName = item(row,column)->text();
    QString s = songName;
//    Client *client = new Client();
//    client->sendData(s.remove(s.right(4)));
    emit signalShowLyric();
//    emit signalPlayMusic(songName);
    PlayMusic(songName);
}

void MusicSongsListWidget::slotGetNextMusic()
{
    //判断当前列表是否为空
    if (tableWidgetIsEmpty())
        return;
    //获取当前行
    int rowIndex = currentIndex().row();
    int totalRow = rowCount();
    qDebug()<<"rowIndex:"<<rowIndex;
    QString str = "";
    if (rowIndex >= 0)
    {
        //到到歌曲列表末尾时，从第一首开始播放
        if (rowIndex < totalRow - 1)
        {
            qDebug()<<"rowIndex:"<<rowIndex;
            str = item(rowIndex + 1,0)->text();
            //设置焦点，若不设置焦点，会总是从第一首个播放
            setCurrentCell(0,0,QItemSelectionModel::Clear);
            setCurrentCell(rowIndex + 1,0,QItemSelectionModel::SelectCurrent);
        }else {
            str = item(0,0)->text();
            //设置焦点，若不设置焦点，会总是从第一首个播放
            setCurrentCell(totalRow,0,QItemSelectionModel::Clear);
            setCurrentCell(0,0,QItemSelectionModel::Select);
        }
#if QDEBUG_OUT
        qDebug()<<"获取下一首歌曲"<<str;
#endif
    }else
    {
        str = item(0,0)->text();
        //设置焦点在第一行
        setCurrentCell(0,0,QItemSelectionModel::Select);
    }
    emit signalSendNextMusic(getMusicPath(str));
}

void MusicSongsListWidget::slotGetPreviouseMusic()
{
    //判断当前列表是否为空
    if (tableWidgetIsEmpty())
        return;
    //获取当前行
    int rowIndex = currentIndex().row();
    QString str = "";
    if (rowIndex >= 1)
    {
        str = item(rowIndex - 1,0)->text();
        //设置焦点，若不设置焦点，会总是从第一首个播放
        setCurrentCell(rowIndex - 1,0,QItemSelectionModel::SelectCurrent);
#if QDEBUG_OUT
        qDebug()<<"获取上一首歌曲"<<str;
#endif
    }else
    {
        str = item(0,0)->text();
        //设置焦点在第一行
        setCurrentCell(0,0,QItemSelectionModel::Select);
    }
    emit signalSendPreviousMusic(getMusicPath(str));
}

void MusicSongsListWidget::slotAddMusic()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFiles);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setNameFilters(myHelper::supportFormatsFilterDialogString());

    if(dialog.exec())
    {
        //导入歌曲名称
        importMusicSongsName(dialog.selectedFiles());
        //导入歌曲名称和路径(程序需要保存歌曲信息时，需要将歌曲的路径存入数据库中，这里暂时没有用到数据库)
        //musicImportSongsSettingPath(dialog.selectedFiles());
    }
}

void MusicSongsListWidget::slotRemoveAllItem()
{
    setRowCount(0);
    clearContents();
}

void MusicSongsListWidget::slotRemoveItem()
{
    int rowIndex = currentRow();
    if (rowIndex != -1)
    {
        removeRow(rowIndex);
    }
}

void MusicSongsListWidget::slotPlayMusic()
{
    QString songName = getSelectContent();
    PlayMusic(songName);
}

void MusicSongsListWidget::PlayMusic(const QString name)
{
//    int index = currentIndex();
    QString musicPath = "";
    if (this->tableWidgetIsEmpty())
    {
        return;
    }else{
        musicPath = this->getMusicPath(name);
    }
#if QDEBUG_OUT
    qDebug()<<"要播放的歌曲为：";
    qDebug()<<"名称:"<<name;
    qDebug()<<"路径："<<musicPath;
#endif
    emit signalPlayMusicPath(musicPath);
}

/*程序启动后，若按下底部控制按钮，播放歌曲，则要先判断列表中是否有歌曲，
 * 若有，则从返回第一手歌曲,若没有则返回空
*/
void MusicSongsListWidget::slotGetFirstPlayMusic()
{
    QString music = "";
    if (tableWidgetIsEmpty()){
        music = "";
    }
    else
    {
        /*判断当前鼠标是否有选中的歌曲，若有则发送选中的，若没有则发送第一首歌曲*/
        //获取当前行
        int rowIndex = currentIndex().row();
        if (rowIndex >= 0)
        {
#if QDEBUG_OUT
            qDebug()<<"开始播放当前选中的歌曲:"<<music;
#endif
            music = item(rowIndex,0)->text();

        }else
        {
            //当前没有任何行被选中，此时发送第一首歌曲
#if QDEBUG_OUT
            qDebug()<<"播放第一首歌曲:"<<music;
#endif
            music = item(0,0)->text();
        }
    }
    emit signalSendFirstPlayMusic(getMusicPath(music));
}

void MusicSongsListWidget::slotSendPlayCmd(int mode)
{
    switch(mode)
    {
    case ORDER_PLAY:            //顺序循环
    case LIST_CIRCUAL:          //列表循环
        slotGetNextMusic();
        break;
    case SINGLE_CIRCUAL:        //单曲循环
        emit signalSendPlayCmdMusicInfo(getMusicPath(getSelectContent()));
        break;
    case SINGLE_PLAY:           //单曲播放
        emit signalSendPlayCmdMusicInfo("");
        break;
    case RADOM_PLAY:            //随机播放
         setRadomPlayMusic();
        break;
    default:
        break;
    }
}

void MusicSongsListWidget::initForm()
{
//    setAttribute(Qt::WA_TranslucentBackground, true);
    //设置没有焦点，这样就可以避免删除时，不选中行也能删除的问题!
    setFocusPolicy(Qt::NoFocus);
    setColumnCount(1);
    setRowCount(0);
    setShowGrid(true);//display the grid
    setEditTriggers(QAbstractItemView::NoEditTriggers);     //设置表格不能编辑
    setSelectionBehavior(QAbstractItemView::SelectRows);    //设置整行选中
    setSelectionMode(QAbstractItemView::SingleSelection);
//    horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    verticalHeader()->setDefaultSectionSize(45);

    QHeaderView *headerview = horizontalHeader();
    headerview->setVisible(false);
    //headerview->resizeSection(0, 300);
    //    headerview->resizeSection(1, 20);
    //    headerview->resizeSection(2, 40);
    verticalHeader()->setVisible(false);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    setLayout(mainLayout);


    //鼠标右键初始化
    m_menu = new MusicListMenu(this);
}

//鼠标右键信号和槽的关联
void MusicSongsListWidget::initConnect()
{
//    connect(m_menu,SIGNAL(signalPlayMusic()),
//            this,SIGNAL(signalPlayMusic()));
    connect(m_menu,SIGNAL(signalPlayMusic()),
            this,SLOT(slotPlayMusic()));
//    connect(m_menu,SIGNAL(signalAddMusic()),
//            this,SIGNAL(signalAddMusic()));
 //   connect(m_menu,SIGNAL(signalAddMusicFolder()),
 //           this,SIGNAL(signalAddMusicFolder()));
  //  connect(m_menu,SIGNAL(signalDeleteMusic()),
  //          this,SIGNAL(signalDeleteMusic()));
    connect(m_menu,SIGNAL(signalDeleteAllMusic()),
            this,SLOT(slotRemoveAllItem()));
    connect(m_menu,SIGNAL(signalDeleteMusic()),
            this,SLOT(slotRemoveItem()));
//    connect(m_menu,SIGNAL(signalDeleteAllMusic()),
//            this,SIGNAL(signalDeleteAllMusic()));

    connect(this,SIGNAL(cellDoubleClicked(int,int)),
            this,SLOT(slotCellDoubleClicked(int,int)));
    connect(m_menu,SIGNAL(signalAddMusic()),this,SLOT(slotAddMusic()));
//    connect(this,SIGNAL(signal))
}

void MusicSongsListWidget::setRadomPlayMusic()
{
    //判断当前列表是否为空
    if (tableWidgetIsEmpty())
        return;
    //获取当前行
    int rowIndex = currentIndex().row();
    int totalRow = rowCount();
    int playIndex =  qrand()%totalRow;
    qDebug()<<"playIndex:"<<playIndex;
    setCurrentCell(playIndex,0,QItemSelectionModel::SelectCurrent);
    QString str = "";

    str = item(playIndex,0)->text();
    qDebug()<<"随机播放";

    emit signalSendNextMusic(getMusicPath(str));
}

void MusicSongsListWidget::contextMenuEvent(QContextMenuEvent *event)
{
    //右键显示菜单
    m_menu->exec(QCursor::pos());
    //窗口关闭
    event->accept();
}

