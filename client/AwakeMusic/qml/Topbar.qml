import QtQuick 2.0
import QtQuick.Window 2.0

Rectangle{
    id:topBar
    height: 50
    width: 1000
    color: "#1e90ff"

    property int mSpace10: 10
    property int iconSideLenth20: 20

    //用户头像
    Rectangle{
        id:userAvatar
        height: 36
        width: 36
        radius: width/2
        anchors.left: parent.left
        anchors.leftMargin: mSpace10
        anchors.verticalCenter: parent.verticalCenter
        Image {
            id: userIamge
            source: "../image/update.png"
        }
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //用户名
    Text {
        id: userName
        text: qsTr("蜗牛")
        color: "white"
        font.pixelSize: 18
        anchors.left: userAvatar.right
        anchors.leftMargin: mSpace10
        anchors.verticalCenter: parent.verticalCenter
        width: text.length * 18
        elide: Text.ElideRight
    }

    //VIP
    Rectangle{
        id:vipUser
        color: "#a9a9a9"
        width: 30
        height: 15
        radius: 8
        anchors.left: userName.right
        anchors.leftMargin: mSpace10
        anchors.verticalCenter: parent.verticalCenter
        Text {
            id: vipText
            text: qsTr("VIP")
            font.pixelSize: 12
            color: "#f5f5dc"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //云
    Image {
        id: privateMusic
        height: iconSideLenth20
        width: iconSideLenth20
        anchors.left: vipUser.right
        anchors.leftMargin: mSpace10
        anchors.verticalCenter: parent.verticalCenter
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //返回按钮
    Image{
        id:returnButton
        width: iconSideLenth20
        height: iconSideLenth20
        anchors.right: refreshButton.left
        anchors.rightMargin: mSpace10
        anchors.verticalCenter: parent.verticalCenter
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //刷新按钮
    Image{
        id:refreshButton
        width: iconSideLenth20
        height: iconSideLenth20
        anchors.right: searchRect.left
        anchors.rightMargin: mSpace10
        anchors.verticalCenter: parent.verticalCenter
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //搜索栏
    Rectangle{
        id:searchRect
        width: 260
        height: 28
        radius: 14
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        color: "#f0fff0"
        Image {
            id: searchImg
            width: iconSideLenth20
            height: iconSideLenth20
            anchors.right: parent.right
            anchors.rightMargin: mSpace10
            anchors.verticalCenter: parent.verticalCenter
            source: "../image/search.png"
        }
        Rectangle{
            width: parent.width - 10
            height: parent.height
            radius:parent.radius
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: mSpace10
            color: "transparent"
            TextInput{
                id:searchInput
                font.pixelSize: 12
                anchors.right: parent.right
                anchors.left: parent.left
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    //听歌识曲
    Image{
        id:listenTosong
        width: iconSideLenth20
        height: iconSideLenth20
        anchors.left: searchRect.right
        anchors.leftMargin: mSpace10
        anchors.verticalCenter: parent.verticalCenter
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //关闭按钮
    Image {
        id: closeButton
        width: iconSideLenth20
        height: iconSideLenth20
        anchors.right: parent.right
        anchors.rightMargin: mSpace10
        anchors.verticalCenter: parent.verticalCenter
        source: "../image/close-normal.png"
        MouseArea{
            anchors.fill: parent
            onClicked: {
                Qt.quit()
            }
        }
    }

    //最小化按钮
    Image{
        id:minWindowButton
        width: iconSideLenth20
        height: iconSideLenth20
        anchors.right: closeButton.left
        anchors.rightMargin: mSpace10
        anchors.verticalCenter: parent.verticalCenter
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                root.visibility = Window.Minimized
            }
        }
    }

    //设置
    Image{
        id:setting
        width: iconSideLenth20
        height: iconSideLenth20
        anchors.right: minWindowButton.left
        anchors.rightMargin: 30
        anchors.verticalCenter: parent.verticalCenter
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //皮肤
    Image{
        id:skinBtn
        width: iconSideLenth20
        height: iconSideLenth20
        anchors.right: setting.left
        anchors.rightMargin: mSpace10
        anchors.verticalCenter: parent.verticalCenter
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //消息
    Image{
        id:messageBtn
        width: iconSideLenth20
        height: iconSideLenth20
        anchors.right: skinBtn.left
        anchors.rightMargin: mSpace10
        anchors.verticalCenter: parent.verticalCenter
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }

    //工具
    Image{
        id:tools
        width: iconSideLenth20
        height: iconSideLenth20
        anchors.right: messageBtn.left
        anchors.rightMargin: mSpace10
        anchors.verticalCenter: parent.verticalCenter
        source: "../image/update.png"
        MouseArea{
            anchors.fill: parent
            onPressed: {
                //待做
            }
        }
    }
}
