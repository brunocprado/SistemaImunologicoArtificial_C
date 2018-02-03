import QtQuick 2.10
import QtQuick.Controls 2.3

ToolTip {
    property int id: 0
    property string tipo: ""
    property string imagem: ""

    parent: parent
    visible: true
    width: 200
    height: 120

    Text{
        color: "#fff"
        width: parent.width
        font.pixelSize: 20
        text: tipo.toUpperCase()
        horizontalAlignment: Text.AlignHCenter
    }

    Image {
        y: 35
        visible: true
        width: 60
        height: 60
        source: imagem
    }

    Column{
        x: 80
        y: 35
        Text{
            color: "#fff"
            text: "ID : " + id
        }
    }
}
