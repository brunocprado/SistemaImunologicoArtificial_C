import QtQuick 2.10
import QtQuick.Controls 2.3
import QtCharts 2.2
import QtQuick.Window 2.3

ApplicationWindow {
    property var virus

    id: estatisticas
    visible: true
    width: 800
    height: 600
    title: "Estatisticas da simulação [ " + virus.identificador + " ]"

    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }

    ChartView {
        title: "Estatisticas"
        anchors.fill: parent
        antialiasing: true
        dropShadowEnabled: true

        ValueAxis {
            id: x
            titleText: "Tempo"
            max: 5
            labelsVisible: false
        }

        ValueAxis {
            id: y
            titleText: "Quantidade"
            max: 20
        }

        SplineSeries {
            id:qtAntigenos
            name: "Antigenos"
            axisX: x
            axisY: y
            onClicked: {
                console.log(point.x,point.y)
            }
        }
    }

    Timer{
        running: parent.visible
        interval: 250
        repeat: true
        onTriggered: {
            if(x.max <= qtAntigenos.count) x.max++;      
            qtAntigenos.append(qtAntigenos.count, virus.quantidade);
            if(virus.quantidade <= 0) running = false;
        }
    }
}
