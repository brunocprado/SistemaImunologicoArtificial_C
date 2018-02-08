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

    Timer{
        running: parent.visible
        repeat: true
        interval: 200
        onTriggered: {
            txtPosicao.text = "Posição : " + sistema.getX(id) + " x " + sistema.getY(id);
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
            text: "ID : " + id
        }

        Text{
            id: txtPosicao
            color: "#fff"
            text: "Posição : " + sistema.getX(id) + " x " + sistema.getY(id)
        }
    }
}
