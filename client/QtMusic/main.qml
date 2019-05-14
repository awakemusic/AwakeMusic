import QtQuick 2.9
import QtQuick.Window 2.2
import QtMultimedia 5.8
import "./qml"
import LocalListModel 1.0

Window {
    id:root
    flags: Qt.FramelessWindowHint
    visible: true
    minimumWidth: 1000
    minimumHeight: 650
    objectName: "rootObject"
    title: "QT音乐播放器"

    //实例化LocalListModel类
    LocalListModel{
        id:localListModel
    }


    MouseArea {
        id: dragRegion
        anchors.fill: parent
        property point clickPos: "0,0"
        onPressed: {
            clickPos  = Qt.point(mouse.x,mouse.y)
            }
        onPositionChanged: {
        //鼠标偏移量
        var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)
        root.x = (root.x+delta.x)
        root.y = (root.y+delta.y)
        }
        onDoubleClicked: {
            if(root.visibility == Window.FullScreen)
                root.visibility = Window.Windowed
            else
                root.visibility = Window.FullScreen
        }
    }


    //主界面
    Rectangle{
        id:mainWindow
        anchors.fill: parent

        //播放器
        MediaPlayer{
            id:mediaPlayer
            volume: 0.5
            source: localListModel.songPath
        }

        //顶部工具栏
        Topbar{
            id:topBar
            anchors.top:parent.top
            anchors.left: parent.left
            anchors.right: parent.right
        }

        //底部工具
        BottomBar{
            id:bottomBar
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
        }

        //左边主界面
        LeftMain{
            id:leftMain
            anchors.bottom: bottomBar.top
            anchors.top: topBar.bottom
            anchors.left: parent.left
        }
    }
}
