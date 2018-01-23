import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Window 2.3

import "../script/script.js" as Script

ApplicationWindow {
    id: janela
    visible: true
    width: 1280
    height: 720
    color: "#c6c6c6"
    title: qsTr("SIA")
    Component.onCompleted: {
        Script.inicia();
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }

    Image {
        id: fundo
        anchors.fill: parent
        fillMode: Image.Stretch
        source: "../imagens/blood.jpg"
    }

    Connections {
        target: sistema
        onAdicionaCelula: {
            Script.cria(id,fundo,tipo,x,y);
        }
        onMovimentaCelula:{
            if(Script.celulas[id] == undefined) return;
            Script.celulas[id].x += mx;
            Script.celulas[id].y += my;
        }
    }

    Drawer {
        id: opcoes
        width: 300
        height: janela.height
        y: menu.height+1
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
            padding: 20
            height: parent.height
            spacing: 10
            width: parent.width

            Switch {
                id: switch1
                text: qsTr("Sim")
                checked: true
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
                    Script.celulas[5].x += 10;
                    Script.celulas[5].y += 10;
                }
            }
        }

        MenuBarItem{
            text: "Opções"
            onClicked: {
                if(opcoes.visible) {
                    opcoes.close();
                    Script.mudaVisibilidade(2,false);
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
                } else {
                    menuPausar.text = "Pausar";
                }
            }
        }

        Menu{
            id: menuEstatisticas
            title: "Estatísticas"
        }

        MenuBarItem{
            text: "Sobre"
        }
    }
}
