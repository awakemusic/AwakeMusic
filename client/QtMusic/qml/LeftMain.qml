import QtQuick 2.0
import "./sub" as Sub
/*
左边主界面
*/

Rectangle{
    id:leftMain
    width: 310
    height: 540
    color: "white"

    //右边界
    Rectangle{
        id:rightBorder
        width: 0.5
        height: parent.height
        color: "#e6e6fa"
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
    }

    //顶部工具栏
    Sub.LeftMainTopBar{
        id:leftMainTopBar
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.right: rightBorder.left
    }

    //本地播放列表
    Sub.LocalPlayList{
        id:localPlaylist
        anchors.top: leftMainTopBar.bottom
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.right: rightBorder.left
    }
}
