import QtQuick 2.10
import QtQuick.Controls 2.3
import QtCharts 2.2

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
//        sistema.start();
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
        id: drawer
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
        opacity: 0.8
        Menu {
            title: "Novo"
            z: 999

            MenuItem {
                text: "Patogeno"
                onClicked: {
                    Script.celulas[5].x += 10;
                    Script.celulas[5].y += 10;
                }
            }
        }

        //        Menu {
        //            on

        //        }
    }







}
