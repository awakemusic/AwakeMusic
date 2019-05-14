import QtQuick 2.0

/*
  左边界面顶部工具栏
*/
Rectangle{
    id:leftMainTopBar
    width: 310
    height: 40
    color: "white"

    property int iconSideLength: 25
    property int mSpace: 35
    //工具栏下边界
    Rectangle{
        id:bottomBorder
        height: 0.6
        width: parent.width
        color: "#e6e6fa"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter
    }

    //本地播放列表
    Image {
        id: localListBtn
        source: "../../image/update.png"
        height: iconSideLength
        width: iconSideLength
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.verticalCenter: parent.verticalCenter
        MouseArea{
            //待做
        }
    }

    //云
    Image {
        id: cloudListBtn
        source: "../../image/update.png"
        height: iconSideLength
        width: iconSideLength
        anchors.left: localListBtn.right
        anchors.leftMargin: mSpace
        anchors.verticalCenter: parent.verticalCenter
        MouseArea{
            //待做
        }
    }

    //电台
    Image {
        id: radioBtn
        source: "../../image/update.png"
        height: iconSideLength
        width: iconSideLength
        anchors.left: cloudListBtn.right
        anchors.leftMargin: mSpace
        anchors.verticalCenter: parent.verticalCenter
        MouseArea{
            //待做
        }
    }

    //手机
    Image {
        id: phoneBtn
        source: "../../image/update.png"
        height: iconSideLength
        width: iconSideLength
        anchors.left: radioBtn.right
        anchors.leftMargin: mSpace
        anchors.verticalCenter: parent.verticalCenter
        MouseArea{
            //待做
        }
    }

    //本地下载列表
    Image {
        id: localDownloadListBtn
        source: "../../image/update.png"
        height: iconSideLength
        width: iconSideLength
        anchors.left: phoneBtn.right
        anchors.leftMargin: mSpace
        anchors.verticalCenter: parent.verticalCenter
        MouseArea{
            //待做
        }
    }
}
