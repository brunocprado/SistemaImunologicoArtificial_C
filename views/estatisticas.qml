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
        id: chart
        title: "Estatisticas"
        anchors.fill: parent
        antialiasing: true
        animationDuration: 200
        animationOptions: ChartView.AllAnimations

        ValueAxis {
            id: x
            titleText: "Tempo"
            max: 5
            shadesColor: "#faa"
        }

        ValueAxis {
            id: y
            titleText: "Quantidade"
            max: 15
        }

        SplineSeries {
            id:qtAntigenos
            name: "Antigenos"
            axisX: x
            axisY: y
            pointLabelsVisible: true
            onClicked: {
                console.log(point.x,point.y)
            }
        }
    }

    Timer{
        running: true
        interval: 1000
        repeat: true
        onTriggered: {
            if(x.max <= qtAntigenos.count) x.max++;
            qtAntigenos.append(qtAntigenos.count, virus.quantidade);
            if(virus.quantidade == 0) running = false;
        }
    }
}
