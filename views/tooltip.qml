import QtQuick 2.10
import QtQuick.Controls 2.3

ToolTip {
    property string tipo: ""
    property string imagem: ""
    property var celula: 0

    parent: parent
    visible: true
    width: 200
    height: 120

    Timer{
        running: parent.visible
        repeat: true
        interval: 500
        onTriggered: {
            txtPosicao.text = "Posição : " + celula.x + " x " + celula.y;
        }
    }

    Text{
        color: "#fff"
        width: parent.width
        font.pixelSize: 18
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
        spacing: 5
        Text{
            color: "#fff"
            text: "ID : " + celula.id
        }

        Text{
            id: txtPosicao
            color: "#fff"
            text: "Posição : " + celula.x + " x " + celula.y
        }
    }
}
