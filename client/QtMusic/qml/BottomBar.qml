import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle{

    property bool isPlay: false
    property string theSongInfo : mediaPlayer.source
    property alias palyBtnSrc: palyBtn.source;
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

    id:bottomBar
    width: 1000
    height: 70
    color: "#1e90ff"

    //作者头像
    Image{
        id:authorAvatar
        width: 69
        height: 69
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: bottomBar.left
        anchors.leftMargin: 10
        source: "../image/update.png"
    }

    //播放暂停按钮
    Image {
        id: palyBtn
        width: 60
        height: 60
        source: "../image/play.png"
            //(isPlay==false) ? "../image/play.png" : "../image/pause.png"
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: lastSongImage.right
        anchors.leftMargin: 5

        MouseArea{
            id:playMouseArea
            anchors.fill: parent
            onPressed: {
                //console.log(theSongInfo)
                //console.log(mediaPlayer.playbackState)
                isPlay = !isPlay
                if(isPlay){
                    mediaPlayer.play()
                    palyBtn.source = "../image/pause.png"
                }
                else{
                   mediaPlayer.pause()
                    palyBtn.source = "../image/play.png";
                }
            }
        }
    }

    //上一曲
    Image {
        id: lastSongImage
        width: 50
        height: 50
        source: "../image/last.png"
        anchors.left: authorAvatar.right
        anchors.leftMargin: 5
        anchors.verticalCenter: parent.verticalCenter
        MouseArea{
            id:lastMouseArea
            anchors.fill: parent
            onPressed: {
                localListModel.lastSong()
                localListModel.searchLocalMusic()
                mediaPlayer.source = localListModel.songPath
                mediaPlayer.play()
            }
        }
    }

    //下一曲
    Image {
        id: nextSongImage
        width: 50
        height: 50
        source: "../image/next.png"
        anchors.left: palyBtn.right
        anchors.leftMargin: 5
        anchors.verticalCenter: parent.verticalCenter
        MouseArea{
            id:nextMouseArea
            anchors.fill: parent
            onPressed: {
                localListModel.nextSong()
                localListModel.searchLocalMusic()
                mediaPlayer.source = localListModel.songPath
                mediaPlayer.play()
            }
        }
    }

    //进度条工具栏
    Rectangle{
        id:progressBar

        color: "transparent"
        height: parent.height
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: nextSongImage.right
        anchors.leftMargin: 10
        anchors.right: loveBtn.left
        anchors.rightMargin: 10

        //当前音质
        Rectangle{
            id:soundQualityBtn
            width: 50
            height: 20
            radius: 20
            color: "transparent"
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.topMargin: 15
            border.color: "white"
            border.width: 1
            Text {
                text: qsTr("标准")
                color: "white"
                font.pixelSize: 12
                font.pointSize: 5
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 8
            }
            //三角形待做
        }

        //歌曲信息栏
        Text {
            id: nameLabel
            text: (mediaPlayer.status == "NoMedia") ? "adsf" : "QT音乐播放器"
            color: "white"
            font.pixelSize: 15
            font.pointSize: 5
            anchors.left: soundQualityBtn.right
            anchors.leftMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 15
        }

        //播放倍速
        Rectangle{
            id:playSpeedBtn
            width: 50
            height: 20
            radius: 20
            color: "transparent"
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.topMargin: 15
            border.color: "white"
            border.width: 1
            Text {
                text: qsTr("倍速")
                color: "white"
                font.pixelSize: 12
                font.pointSize: 10
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 8
            }
            //三角形待做
        }

        //播放时间进度
        Text {
            id: timeInfo
            text: qsTr(currentTime(mediaPlayer.position)+"/"+
                       currentTime(mediaPlayer.duration))
            color: "white"
            font.pixelSize: 12
            anchors.right: parent.right
            anchors.bottom : parent.bottom
            anchors.bottomMargin: 15
        }
        //进度条
        Slider{
            id:playProgressBar
            anchors.bottom : parent.bottom
            anchors.bottomMargin: 15
            anchors.left: parent.left
            anchors.right: timeInfo.left
            anchors.rightMargin: 10
            value: mediaPlayer.position
            maximumValue: mediaPlayer.duration
            style: SliderStyle{
                groove: Rectangle{
                    implicitWidth: playProgressBar.width
                    implicitHeight: 2
                    color: "red"
                    radius: 2
                    Rectangle{
                        anchors.left: parent.left
                        anchors.top: parent.top
                        anchors.bottom: parent.bottom
                        color: "#e6e6fa"
                        width: playProgressBar.width
                    }
                }
                handle: Rectangle {
                    anchors.centerIn: parent
                    color: "#f0ffff"
                    //border.color: "#f0ffff"
                    //border.width: 2
                    implicitWidth: 10
                    implicitHeight: 10
                    radius:5
                    Rectangle{
                        width: parent.width-8
                        height: width
                        radius: width/2
                        color: "#f0ffff"
                        anchors.centerIn: parent
                    }
                }
            }

            onValueChanged: {
                //console.log(playProgressBar.value)
                if(mediaPlayer.seekable){
                    mediaPlayer.seek(playProgressBar.value)
                }
            }
        }
    }

    //当前播放队列歌曲数量
    Text {
        id: songSum
        text: qsTr("0")
        font.pixelSize: 18
        font.pointSize: 5
        color: "white"
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: parent.right
        anchors.rightMargin: 20
    }

    //播放队列
    Image{
        id:playingListBtn
        height: 25
        width: 25
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: songSum.left
        anchors.rightMargin: 1
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //评论
    Image{
        id:discuss
        width: 25
        height: 25
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: playingListBtn.left
        anchors.rightMargin: 20
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //显示歌词
    Image{
        id:showLyrics
        width: 25
        height: 25
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: discuss.left
        anchors.rightMargin: 20
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //音效
    Rectangle{
        id:effectButton
        height: 20
        width: 50
        radius: 20
        color: "transparent"
        border.color: "white"
        border.width: 1
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: showLyrics.left
        anchors.rightMargin: 20

        Rectangle{
            width: 8
            height: 8
            radius: width/2
            color: "#00ff00"
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 8
        }
        Text {
            text: qsTr("音效")
            color: "white"
            font.pixelSize: 12
            anchors.verticalCenter: parent.verticalCenter
            anchors.right: parent.right
            anchors.rightMargin: 8
        }
    }

    //音量调节
    Image {
        id: setVolume
        width: 20
        height: 20
        source: "../image/volume-high-icon.png"
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: effectButton.left
        anchors.rightMargin: 20
        Slider{
            id:verticalSlider
            visible: false
            orientation: Qt.Vertical
            value: mediaPlayer.volume
            stepSize: 0.1
            anchors.bottom: setVolume.top
            anchors.horizontalCenter: setVolume.horizontalCenter

            onValueChanged: {
                mediaPlayer.volume = verticalSlider.value
            }
        }
        MouseArea{
            anchors.fill: parent
            hoverEnabled: true
            onPressed: {
                verticalSlider.visible = !verticalSlider.visible
            }
        }
    }

    //播放模式
    Image {
        id: playMode
        width: 25
        height: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: setVolume.left
        anchors.rightMargin: 20
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //更多
    Image {
        id: more
        width: 20
        height: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: playMode.left
        anchors.rightMargin: 20
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //下载
    Image {
        id: downlaodButton
        width: 20
        height: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: more.left
        anchors.rightMargin: 20
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //喜欢
    Image {
        id: loveBtn
        width: 20
        height: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.right: downlaodButton.left
        anchors.rightMargin: 20
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }
}
