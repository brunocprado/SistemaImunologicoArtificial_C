import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

ApplicationWindow {
    id: novoSistema
    width: 600
    height: 380
    property alias toolTip: toolTip
    visible: true
    Material.accent: Material.Red

    Text {
        x: 17
        y: 14
        text: qsTr("Novo sistema")
        font.family: "Roboto"
        font.pixelSize: 22
    }

    TextField {
        id: txtGerador
        x: 17
        y: 56
        width: 260
        height: 36
        font.pixelSize: 14
        text: qsTr("")
        bottomPadding: 10
        placeholderText: "Gerador"
        Material.accent: Material.Red

    }

    GroupBox {
        x: 17
        y: 120
        width: 568
        height: 182
        title: qsTr("Leucócitos a serem simulados")
        //Material.theme: Material.Dark

        Column {
            width: 197
            height: 135
            spacing: 5

            Row {
                width: 200
                height: 30

                RadioButton {
                    id: radioButton
                    y: 0
                    width: 150
                    height: 30
                    text: qsTr("Macrófagos")
                    autoExclusive: false
                    checked: true
                }

                RoundButton {
                    id: roundButton
                    width: 30
                    height: 30
                    text: "+"
                    ToolTip{
                        id: toolTip
                        visible: parent.activeFocus
                        width:180
                        height:120
                        rightMargin: 0

                        TextField {
                            id: textField
                            text: qsTr("Text Field")
                        }


                    }
                }
            }

            Row {
                width: 200
                height: 30
                RadioButton {
                    id: radioButton1
                    y: 0
                    width: 150
                    height: 30
                    text: qsTr("Neutrófilos")
                    checked: true
                    autoExclusive: false
                }

                RoundButton {
                    id: roundButton1
                    width: 30
                    height: 30
                    text: "+"
                }
            }

            Row {
                width: 200
                height: 30
                RadioButton {
                    id: radioButton2
                    y: 0
                    width: 150
                    height: 30
                    text: qsTr("Macrófagos")
                    checked: true
                    autoExclusive: false
                }

                RoundButton {
                    id: roundButton2
                    width: 30
                    height: 30
                    text: "+"
                }
            }

            Row {
                width: 200
                height: 30
                RadioButton {
                    id: radioButton3
                    y: 0
                    width: 150
                    height: 30
                    text: qsTr("Macrófagos")
                    checked: true
                    autoExclusive: false
                }

                RoundButton {
                    id: roundButton3
                    width: 30
                    height: 30
                    text: "+"
                }
            }

        }
    }


    Button {
        id: btnOk
        x: 521
        y: 320
        text: qsTr("OK")
        Material.accent: Material.Red
        onPressed: {
            sistema.novoSistema(txtGerador.text)
        }
    }
}
