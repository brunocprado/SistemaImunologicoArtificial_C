import QtQuick 2.11
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

ApplicationWindow {
    id: novoSistema
    width: 600
    height: 455
    visible: true
    title: "Nova simulação"
    minimumHeight: height
    minimumWidth: width
    maximumHeight: minimumHeight
    maximumWidth: minimumWidth

    property var parametros: ({})

    Component.onCompleted: {
        parametros = JSON.parse(sistema.getParametros());
        for(var i in parametros) listaParametros.append({valorTexto: i,valor:parametros[i]});
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
                    validator: IntValidator {bottom: 0;}
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
//                    Material.accent: "#"
                }

                Text {
                    id: lblLegenda
                    visible: btnExibeLegendanda.hovered
                    width: 320
                    height: 35
                    text: "Seed do gerador do sistema. Um gerador X sempre irá resultar na mesma simulação. (Padrão = 0)"
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
                x: 335
                y: 98
                width: 240
                spacing: 20

                Text {
                    height: 40
                    text: qsTr("Quantidade de antígenos")
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                }

                TextField {
                    id: txtQt
                    width: 80
                    validator: IntValidator {bottom: 0; top: 999;}
                    horizontalAlignment: Text.AlignHCenter
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

                    RadioButton {
                        id: radioMacrofagos
                        y: 0
                        width: 150
                        height: 30
                        text: qsTr("Macrófagos")
                        autoExclusive: false
                        checked: true
                    }

                    RadioButton {
                        id: radioNeutrofilos
                        y: 0
                        width: 150
                        height: 30
                        text: qsTr("Neutrófilos")
                        checked: true
                        autoExclusive: false
                    }

                    RadioButton {
                        id: radioButton2
                        y: 0
                        width: 150
                        height: 30
                        text: qsTr("Linfócitos B")
                        checked: true
                        autoExclusive: false
                    }

                    RadioButton {
                        id: radioButton3
                        y: 0
                        width: 150
                        height: 30
                        text: qsTr("Linfócitos T")
                        checked: true
                        autoExclusive: false
                    }
                }
            }

            Button {
                x: 511
                y: 336
                text: qsTr("OK")
                Material.accent: Material.Red
                onPressed: {
                    var tmp = {};
                    tmp["gerador"] = (txtGerador.text != "") ? parseInt(txtGerador.text) : 0;
                    tmp["qt"] = (radioInicia.checked && txtQt.text != "") ? parseInt(txtQt.text) : 10;
                    if(!radioInicia.checked) tmp["qt"] = 0;
                    tmp["parametros"] = parametros;
                    sistema.novoSistema(JSON.stringify(tmp));
                    if(radioInicia.checked) temporizador.running = true;
                    novoSistema.close();
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
                        onTextChanged: {
                            parametros[valorTexto] = text;
                        }
                        MouseArea{
                            x: 120
                            y: 10
                            width: 20
                            height: 20
                            cursorShape: Qt.PointingHandCursor
                            Image { source: "../imagens/apagar.png" }
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
