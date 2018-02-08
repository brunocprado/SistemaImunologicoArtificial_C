import QtQuick 2.10
import QtQuick.Controls 2.3

ApplicationWindow {
    id: novoVirus
    width: 400
    height: 450
    visible: true
    color: "#888"

    Component.onCompleted: {
        console.log("TESTE")
    }

    GroupBox {
        id: groupBox
        x: 13
        y: 13
        width: 364
        height: 94
        title: qsTr("Group Box")

        TextInput {
            id: textInput
            x: 0
            y: 24
            width: 261
            height: 20
            text: qsTr("")
            font.pixelSize: 12
        }

        Text {
            id: text1
            x: 0
            y: 4
            text: qsTr("Identificador")
            font.pixelSize: 12
        }
    }

    Button {
        x: 315
        y: 400
        width: 78
        height: 35
        text: "Novo"
    }

}
