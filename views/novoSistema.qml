import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

ApplicationWindow {
    id: novoSistema
    width: 600
    height: 380
    visible: true
    //    color: "#6a3030"
    Material.accent: Material.Red
    Component.onCompleted: {
        console.log("TESTE")
    }

    GroupBox {
        id: groupBox
        x: 17
        y: 120
        width: 568
        height: 182
        title: qsTr("Leucócitos a serem simulados")
        //Material.theme: Material.Dark

        Column {
            id: column
            width: 225
            height: 135
            spacing: 5

            RadioButton {
                id: radioButton
                width: 127
                height: 30
                text: qsTr("Macrófagos")
                autoExclusive: false
                checked: true
            }

            RadioButton {
                id: radioButton1
                height: 30
                text: qsTr("Neutrófilos")
                autoExclusive: false
                checked: true
            }

            RadioButton {
                id: radioButton2
                height: 30
                text: qsTr("Linfócitos")
                checked: true
                autoExclusive: false
            }

            RadioButton {
                id: radioButton3
                height: 30
                text: qsTr("Radio Button")
                checked: true
                autoExclusive: false
            }
        }
    }

    Button {
        id: button
        x: 521
        y: 320
        text: qsTr("OK")
        Material.accent: Material.Red
    }

    Text {
        id: text1
        x: 17
        y: 14
        text: qsTr("Novo sistema")
        font.family: "Roboto"
        font.pixelSize: 22
    }

    TextField {
        id: textField
        x: 17
        y: 56
        width: 258
        height: 36
        font.pixelSize: 14
        text: qsTr("")
        bottomPadding: 10
        placeholderText: "Gerador"
        Material.accent: Material.Red
    }

    RoundButton {
        id: roundButton
        x: 286
        y: 58
        width: 30
        height: 30
        text: "?"
        font.bold: true
        font.pointSize: 10

        ToolTip{
            leftMargin: -0.3
            parent: parent
            visible: parent.activeFocus
            Text{
                text: "TESTE"
            }
        }
    }


}
