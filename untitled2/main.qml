import QtQuick 2.9
import QtQuick.Window 2.2
import QtMultimedia 5.0
import QtQuick.Controls 1.1
import QtQuick.Layouts 1.1
import QtQuick.Dialogs 1.0

ApplicationWindow{
    id:window
    width:300
    height: 300
    visible: true
    toolBar: ToolBar{
        id:toolBar
//        ToolButton{
//            text: "…";
//            onClicked: fileDialog.open()
//            FileDialog{
//                id: fileDialog
//                title: "Open file"
//                nameFilters: [qsTr("MP3 files(*.mp3)"),qsTr("All files(*.*)")]
//                onAccepted: mediaPlayer.source = fileDialog.fileUrl;
//            }
//        }

        ToolButton{
            text: mediaPlayer.metaData.title;
            onClicked: {
                mediaPlayer.source = "file:///root/CloudMusic/song.mp3"
//                mediaPlayer.source = qsTr("rtsp://192.168.30.145/song.mp33")
                mediaPlayer.play();
            }
        }
    }
    Row{
        anchors.bottom: parent.bottom
        ToolButton{
            height: 30
            width: 30
            Image{
                id: pause
                anchors.fill: parent
                source: "/resources/img/play"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        mediaPlayer.pause();
                        pause.visible = false;
                        play.visible = true;
                    }
                }
            }
            Image{
                id:play
                anchors.fill: parent
                visible: false
                source:"/resources/img/pause"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        mediaPlayer.play();
                        pause.visible = true;
                        play.visible = false;
                    }
                }
            }
        }
        Slider{
            maximumValue: mediaPlayer.duration;
            value: mediaPlayer.position;
            onValueChanged: mediaPlayer.seek(value);
        }
        Text{
            text:parent.currentTime(mediaPlayer.position)+"/"+parent.currentTime(mediaPlayer.duration);
            color: "black"
        }

        Image{
            height: 30
            width: 30
            source: "/resources/img/volumn"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    if(volume.visible)
                        volume.visible = false;
                    else
                        volume.visible = true;
                }
            }
        }
        Slider{
            id: volume
            visible: false
            maximumValue: 1.0
            value: mediaPlayer.volume
            onValueChanged: mediaPlayer.volume = value
        }
        function currentTime(time)
        {
            var sec= Math.floor(time/1000);
            var hours=Math.floor(sec/3600);
            var minutes=Math.floor((sec-hours*3600)/60);
            var seconds=sec-hours*3600-minutes*60;
            var hh,mm,ss;
            if(hours.toString().length<2)
                hh="0"+hours.toString();
            else
                hh=hours.toString();
            if(minutes.toString().length<2)
                mm="0"+minutes.toString();
            else
                mm=minutes.toString();
            if(seconds.toString().length<2)
                ss="0"+seconds.toString();
            else
                ss=seconds.toString();
            return hh+":"+mm+":"+ss
        }
        SpinBox{
            value:1;
            onValueChanged: mediaPlayer.loops = value;
        }
    }//https://blog.csdn.net/u013207966/article/details/51312811
    MediaPlayer{id: mediaPlayer}
    VideoOutput{anchors.fill: parent;source: mediaPlayer}
}
