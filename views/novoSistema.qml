import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

ApplicationWindow {
    id: novoSistema
    width: 600
    height: 460
    visible: true
    title: "Nova simulação"

    Component.onCompleted: {
        var tmp = JSON.parse(sistema.getParametros());
        for(var i in tmp){
            listaParametros.append({valorTexto: i,valor:tmp[i]});
        }
    }

    TabBar {
        id: seletorAba
        width: parent.width
        z: 100

        TabButton{ text: "Simulação" }
        TabButton{ text: "Parâmetros" }
    }

    SwipeView{
        y: 50
        width: parent.width
        currentIndex: seletorAba.currentIndex

        Pane{
            height: 40
            padding: 15

            Text {
                text: qsTr("Novo sistema")
                font.wordSpacing: -0.2
                font.family: "Roboto"
                font.pixelSize: 22
            }



            Row {
                x: 5
                y: 50
                width: 570
                height: 37
                spacing: 20

                TextField {
                    id: txtGerador
                    width: 120
                    height: 36
                    font.pixelSize: 14
                    text: qsTr("")
                    bottomPadding: 10
                    placeholderText: "Gerador"
                    Material.accent: Material.Red
                }

                RoundButton {
                    id: btnExibeLegendanda
                    width: 36
                    height: 36
                    text: "?"
                    checkable: false
                }

                Text {
                    id: lblLegenda
                    visible: btnExibeLegendanda.hovered
                    width: 320
                    height: 35
                    text: qsTr("Seed do gerador do sistema. Um gerador X sempre irá resultar na mesma simulação")
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                    topPadding: 0
                    font.family: "Verdana"
                }

            }

            RadioButton {
                id: radioInicia
                x: 0
                y: 98
                height: 40
                text: qsTr("Inicializar")
                autoExclusive: false
                checkable: true
                checked: true
            }

            Row {
                visible: radioInicia.checked
                x: 294
                y: 98
                width: 280
                spacing: 20

                Text {
                    height: 40
                    text: qsTr("Quantidade de antígenos")
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                }

                TextField {
                    id: txtQt
                    text: qsTr("")
                    placeholderText: "10"
                }
            }

            GroupBox {
                x: 5
                y: 148
                width: 570
                height: 182
                title: qsTr("Leucócitos a serem simulados")

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
                x: 511
                y: 336
                text: qsTr("OK")
                Material.accent: Material.Red
                onPressed: {
                    //                    console.info(listaParametros)
                    sistema.novoSistema(txtGerador.text)
                }
            }





        }

        Pane {
            padding: 10

            Rectangle{
                color: '#fafafa'
                width: parent.width
                height: 40
                z: 50
                Row{
                    Text{
                        leftPadding: 10
                        height: 40
                        width: lista.width - 150
                        text: "Parâmetro"
                        verticalAlignment: Text.AlignVCenter
                        font.bold: true
                        font.family: "Roboto"
                        font.pixelSize: 14
                    }

                    Text{
                        height: 40
                        width: 100
                        horizontalAlignment: Text.AlignHCenter
                        text: "Valor"
                        verticalAlignment: Text.AlignVCenter
                        font.bold: true
                        font.family: "Roboto"
                        font.pixelSize: 14
                    }
                }
            }

            ListView{
                y: 45
                id: lista
                width: parent.width
                height: 340
                model: ListModel { id: listaParametros }
                delegate: Row{
                    Text{
                        leftPadding: 10
                        height: 40
                        width: lista.width - 150
                        text: valorTexto
                        verticalAlignment: Text.AlignVCenter
                    }

                    TextField{
                        y: 2
                        height: 40
                        width: 100
                        placeholderText: valor
                        inputMethodHints: Qt.ImhFormattedNumbersOnly
                        MouseArea{
                            x: 120
                            y: 10
                            width: 20
                            height: 20
                            cursorShape: Qt.PointingHandCursor
                            Image {
                                source: "../imagens/apagar.png"
                            }
                            onClicked: {
                                parent.text = ""
                            }
                        }
                    }
                }
            }
        }
    }
}
