import QtQuick 2.10
import QtQuick.Controls 2.3

ApplicationWindow {
    id: novoVirus
    width: 400
    height: 450
    visible: true
    color: "#ccc"

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

        Text {
            id: text1
            x: 0
            y: 0
            text: qsTr("Identificador")
            font.pixelSize: 12
        }

        TextField {
            id: textField
            x: 0
            y: 16
            width: 340
            height: 43
            text: qsTr("Text Field")
        }
    }

    Button {
        x: 312
        y: 393
        width: 78
        height: 46
        text: "Novo"
    }

}
