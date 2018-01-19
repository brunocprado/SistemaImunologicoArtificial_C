import QtQuick 2.10
import QtQuick.Controls 2.3
import QtCharts 2.2

import "script/script.js" as Script

ApplicationWindow {
    id: janela
    visible: true
    width: 1280
    height: 720
    color: "#c6c6c6"
    title: qsTr("SIA")
    Component.onCompleted: Script.inicia();

    Image {
        id: fundo
        transformOrigin: Item.TopLeft
        scale: 0.6
        //        transformOrigin: Item.TopLeft
        //        width: 1600
        //        height: 900
        //        anchors.rightMargin: -425
        //        anchors.bottomMargin: -238
        //        scale: 0.75
        anchors.fill: parent
        fillMode: Image.Stretch
        source: "imagens/blood.jpg"
        ChartView {
            title: "Line"
            anchors.fill: parent
            antialiasing: true

            LineSeries {
                name: "LineSeries"
                XYPoint { x: 0; y: 0 }
                XYPoint { x: 1.1; y: 2.1 }
                XYPoint { x: 1.9; y: 3.3 }
                XYPoint { x: 2.1; y: 2.1 }
                XYPoint { x: 2.9; y: 4.9 }
                XYPoint { x: 3.4; y: 3.0 }
                XYPoint { x: 4.1; y: 3.3 }
            }
        }
    }

    Connections {
        target: sistema
        onAdicionaCelula: {

            Script.cria(id,fundo,tipo,x,y);
        }
        onMovimentaCelula:{
            //            console.log(Script.celulas[id].x);
            //            Script.celulas[id].x = mx;
            //            Script.celulas[id].y = my;
            //            console.log(Script.celulas[id].x);
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
                    //                    console.log("TESTE");
                    //                    console.log(teste.renderiza())
//                    Script.celulas[20].x += 10;
//                    Script.celulas[20].y += 10;
                }
            }
        }

        //        Menu {
        //            on

        //        }
    }







}
