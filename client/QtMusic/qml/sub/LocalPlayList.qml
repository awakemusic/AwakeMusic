import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls 2.4
import QtQml.Models 2.11


/*
  本地播放列表
  LeftMian的子页之一
*/

Rectangle{
    id:localPlaylist
    width: 310
    height: 490
    color: "white"

    property bool isPlay: false

    //时间格式化
    function currentTime(time){
        var sec = Math.floor(time/1000)
        var minutes = Math.floor(sec/60)
        var seconds = sec - minutes*60
        var ss,mm
        if(seconds.toString().length<2)
            ss = "0"+seconds.toString()
        else
            ss = seconds.toString()
        if(minutes.toString().length<2)
            mm = "0"+minutes.toString()
        else
            mm = minutes.toString()
        return mm + ":" + ss
    }


    //列表显示歌曲名字
    function showSongName(index){
        var songName
        for(var i = 0;i < localListModel.songCount;i++){
            switch(index){
            case i:
                songName = localListModel.vSongName[i]
                break;
            default:
                break
            }
        }
        return songName
    }

    //列表名称栏
    Rectangle{
        id:topTitleRec
        width: localPlaylist.width
        height: 40
        Image {
            id: openList
            source: "../../image/update.png"
            width: 20
            height: 20
            anchors.left: parent.left
            anchors.leftMargin: 5
            anchors.verticalCenter: parent.verticalCenter
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    //loc.show()
                    if(playingList.visible == true)
                        playingList.visible = false
                    else
                        playingList.visible = true
                }
            }
        }
        Text {
            id: listTitle
            text: qsTr("默认列表["+localListModel.songCount+"]")
            font.pixelSize: 18
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: openList.right
            anchors.leftMargin: 5
        }
    }

    //下边界线
    Rectangle{
        id:bottomBorder
        width: parent.width
        height: 0.5
        color: "#e6e6fa"
        anchors.top:topTitleRec.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    //列表栏
    Rectangle{
        id:playingList
        width: localPlaylist.width
        anchors.top: bottomBorder.bottom
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: localPlaylist.horizontalCenter
        color:"white"
        visible: false

        //竖直滚动条
        Rectangle{
            id:scrollBar
            width: 10
            color: "#b0c4de"
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            visible: listView.contentHeight>listView.height ? true : false;

            //滚动按钮
            Rectangle{
                id:scrollBtn
                width: parent.width + 2
                height: 95
                color: "#778899"
                anchors.horizontalCenter: parent.horizontalCenter


               MouseArea{
                   anchors.fill: parent
                   drag.target: scrollBtn
                   drag.axis: Drag.YAxis
                   drag.minimumY: 0
                   drag.maximumY: scrollBar.height - scrollBtn.height

                   onMouseYChanged: {
                       listView.contentY = scrollBtn.y * (listView.contentHeight-listView.height) / (scrollBar.height-scrollBtn.height);
                   }
               }
            }
        }

        //显示歌曲的列表
        ListView{
            id:listView
            model:localListModel.songCount
            anchors.fill: parent
            clip: true
            focus: true
            keyNavigationWraps: true
            //spacing: 20
            delegate: listDelegate
            onContentYChanged: {
                if (listView.contentY < 0) {
                    scrollBtn.y = 0;
                    return;
                }

                scrollBtn.y = listView.contentY * (scrollBar.height-scrollBtn.height) / (listView.contentHeight-listView.height) > (scrollBar.height - scrollBtn.height) ?
                            (scrollBar.height - scrollBtn.height) :
                            listView.contentY * (scrollBar.height-scrollBtn.height) / (listView.contentHeight-listView.height);
            }
        }
    }

    //delegate组键
       Component{
        id:listDelegate
        Rectangle{
            id:mainItem
            height: 30
            width: parent.width
            color: "white"


            //加入播放按钮
            Image {
                id: addPlayListBtn
                source: "../../image/update.png"
                width: 20
                height: 20
                visible: false
                anchors.left: mainItem.left
                anchors.leftMargin: 4
                anchors.verticalCenter: mainItem.verticalCenter
                MouseArea{
                    anchors.fill: parent
                    //待做
                }
            }

            //歌名
            Text {
                id: songNameText
                text: showSongName(index)
                font.pixelSize: 12
                color: "black"
                anchors.left: addPlayListBtn.right
                anchors.leftMargin: 6
                anchors.right: mvBtn.left
                anchors.verticalCenter: mainItem.verticalCenter
                font.bold: true
                elide: Text.ElideRight
            }

            //时间
            Text {
                id: timeInfo
                text: qsTr(currentTime(localListModel.vSongTime[index]*1000))
                color: "black"
                visible: false
                font.pixelSize: 12
                anchors.verticalCenter: mainItem.verticalCenter
                anchors.right: mainItem.right
                anchors.rightMargin: 20
            }

            //喜爱/删除/更多
            Rectangle{
                id:loveDeleteMoreRect
                visible: false
                anchors.right: mainItem.right
                anchors.rightMargin: 20
                anchors.left: mvBtn.right
                anchors.leftMargin: 20
                anchors.verticalCenter: mainItem.verticalCenter
                //更多
                Image {
                    id: moreBtn
                    source: "../../image/update.png"
                    width: 20
                    height: 20
                    anchors.right: parent.right
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea{
                        anchors.fill: parent
                        //待做
                    }
                }
                //删除
                Image {
                    id: deleteBtn
                    source: "../../image/update.png"
                    width: 20
                    height: 20
                    anchors.right: moreBtn.left
                    anchors.rightMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea{
                        anchors.fill: parent
                        //待做
                    }
                }
                //喜爱
                Image {
                    id: loveBtn
                    source: "../../image/update.png"
                    width: 20
                    height: 20
                    anchors.right: deleteBtn.left
                    anchors.rightMargin: 10
                    anchors.verticalCenter: parent.verticalCenter
                    MouseArea{
                        anchors.fill: parent
                        //待做
                    }
                }
            }

            //MV
            Image {
                id: mvBtn
                source: "../../image/update.png"
                width: 20
                height: 20
                anchors.right: parent.right
                anchors.rightMargin: 110
                anchors.verticalCenter: mainItem.verticalCenter
                MouseArea{
                    anchors.fill: parent
                }
            }

            MouseArea{
                anchors.fill: parent
                hoverEnabled: true
                onDoubleClicked: {
                    localListModel.setIndex(index)
                    localListModel.searchLocalMusic()
                    mediaPlayer.source = localListModel.songPath
                    mediaPlayer.play()
                    bottomBar.isPlay = true
                    bottomBar.palyBtnSrc = "../../image/pause.png"
                }

                onEntered: {
                    mainItem.color = "#f0fff0"
                    addPlayListBtn.visible = true
                    loveDeleteMoreRect.visible = true
                    timeInfo.visible = false
                }
                onExited: {
                    mainItem.color = "white"
                    addPlayListBtn.visible = false
                    loveDeleteMoreRect.visible = false
                    timeInfo.visible = true
                }
            }
        }
    }
}
