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
    Loader { id: pageLoader }
    Column{
        anchors.fill:parent;
        Row{
            Text{
                text: "用户名";
            }
            TextField{
            }
        }
        Row{
            Text{
                text: "密码：";
            }
            TextField{
            }
        }
        Row{
            Button{
                text: "登录"
                MouseArea {
                    anchors.fill: parent;
                    onClicked: pageLoader.source = "main.qml";    }
            }
            Button{
                text: "注册"
            }
        }
    }
}
