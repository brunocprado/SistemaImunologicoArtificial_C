import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Window 2.3

import "../script/script.js" as Script

ApplicationWindow {
    id: janela
    visible: true
    width: 1600
    height: 900
    minimumHeight: 600
    minimumWidth: 1000
    color: "#c6c6c6"
    title: "Sistema imunológico artificial C++"

    Shortcut {
        sequences: ["Ctrl++","A"]
        onActivated: celulas.scale += 0.2
    }

    Shortcut {
        sequences: ["Ctrl+-","S"]
        onActivated: if(celulas.scale > 1) celulas.scale -= 0.2
    }

    Component.onCompleted: {
        Script.inicia();
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }

    Component.onDestruction:  {
        sistema.encerra();
        Qt.quit();
    }

    onWidthChanged: {
        if(width > 1600 && celulas.scale == 1){
            celulas.scale = width/1600;
        }
    }

    Connections {
        target: sistema
        onAdicionaCelula: {
            Script.cria(id,celulas,tipo,x,y);
        }
        onMovimentaCelula: {
            if(Script.celulas[id] === undefined) return;
            Script.celulas[id].x = mx;
            Script.celulas[id].y = my;
        }
        onAdicionaComposto: {
            Script.addComposto(celulas,id,tipo,raio,x,y);
        }
        onMudaComposto: {
            Script.compostos[id].x -= varRaio;
            Script.compostos[id].y -= varRaio;
            Script.compostos[id].width += varRaio * 2;
            Script.compostos[id].opacity -= 0.1;
        }
        onEliminaComposto: {
            Script.compostos[id].destroy();
            delete Script.compostos[id];
        }
    }

    Timer{
        running: true
        repeat: true
        interval: 1000
        property int segundos: 0
        onTriggered: {
            segundos++;
            janela.title = "Sistema imunológico artificial C++ " + segundos;
        }

    }

    Image {
        id: fundo
        anchors.fill: parent
        fillMode: Image.Stretch
        source: "../imagens/blood.jpg"

        Flickable{
            contentWidth: 1600 * celulas.scale
            contentHeight: 900 * celulas.scale
            anchors.fill: parent

            Frame{
                id: celulas
                transformOrigin: Item.TopLeft
                anchors.fill: parent
            }
        }
    }

    menuBar: MenuBar {
        id: menu
        opacity: 1
        Menu {
            title: "Novo"
            z: 999

            MenuItem {
                text: "Sistema"
                onClicked: {
                    Script.novoSistema();
                }
            }

            MenuItem {
                text: "Patogeno"
                onClicked: {
                    sistema.addPatogeno();
                }
            }
        }

        MenuBarItem{
            text: "Opções"
            onClicked: {
                if(opcoes.visible) {
                    opcoes.close();
                } else {
                    opcoes.open();
                }
            }
        }

        MenuBarItem{
            id: menuPausar
            text: "Pausar"
            onClicked:{
                if(menuPausar.text == "Pausar"){
                    menuPausar.text = "Resumir";
                    sistema.pausar();
                } else {
                    menuPausar.text = "Pausar";
                    sistema.resumir();
                }
            }
        }

        Menu{
            id: menuEstatisticas
            title: "Estatísticas"

            MenuItem{
                text: "Estatisticas gerais"
                onClicked: {
                    Script.viewEstatisticas.createObject(janela,{});
                }
            }
        }

        MenuBarItem{
            text: "Sobre"
            onClicked: {
                var tmp = Qt.createComponent("../views/sobre.qml");
                tmp.createObject(janela,{});
            }
        }
    }

    Drawer {
        id: opcoes
        width: 320
        height: janela.height
        y: menu.height
        background: Rectangle {
            color: "#8f4f4f"
            Rectangle {
                x: parent.width - 1
                width: 1
                height: parent.height
                color: "#555"
            }
        }

        Column {
            id: column
            width: 300
            padding: 20
            height: parent.height
            spacing: 30

            Row {
                width: 260
                height: 60
                Column {
                    width: 180
                    height: 50
                    spacing: 10

                    Text {
                        color: "#ffffff"
                        text: qsTr("CAMADA QUÍMICA")
                        font.bold: true
                        font.family: "Arial"
                        verticalAlignment: Text.AlignTop
                        fontSizeMode: Text.Fit
                        font.pixelSize: 15
                    }

                    Text {
                        width: 200
                        color: "#ffffff"
                        text: qsTr("Exibe emissão de compostos químicos")
                        wrapMode: Text.WordWrap
                        font.pixelSize: 12
                    }
                }
                Switch {
                    height: 30
                    text: qsTr("Sim")
                    checked: true
                }
            }

            //SEGUNDO SLIDER
            Row {
                width: 260
                height: 60
                Column {
                    width: 180
                    height: 50
                    spacing: 10

                    Text {
                        color: "#ffffff"
                        text: qsTr("DEBUG")
                        font.bold: true
                        font.family: "Arial"
                        verticalAlignment: Text.AlignTop
                        fontSizeMode: Text.Fit
                        font.pixelSize: 15
                    }

                    Text {
                        width: 200
                        color: "#ffffff"
                        text: qsTr("Imprime informações de desenvolvedor")
                        wrapMode: Text.WordWrap
                        font.pixelSize: 12
                    }
                }
                Switch {
                    height: 30
                    text: qsTr("Sim")
                    checked: true
                }
            }

            //TERCEIRO SLIDER

            Row {
                width: 260
                height: 60
                Column {
                    width: 180
                    height: 50
                    spacing: 10
                    Text {
                        color: "#ffffff"
                        text: qsTr("MACROFAGOS")
                        verticalAlignment: Text.AlignTop
                        fontSizeMode: Text.Fit
                        font.bold: true
                        font.pixelSize: 15
                        font.family: "Arial"
                    }

                    Text {
                        width: 200
                        color: "#ffffff"
                        text: qsTr("Imprime informações de desenvolvedor")
                        wrapMode: Text.WordWrap
                        font.pixelSize: 12
                    }
                }

                Switch {
                    height: 30
                    text: qsTr("Sim")
                    checked: true
                    onClicked: {
                        Script.mudaVisibilidade(2);
                    }
                }
            }


        }
    }
}
