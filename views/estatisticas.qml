import QtQuick 2.10
import QtQuick.Controls 2.3
import QtCharts 2.2
import QtQuick.Window 2.3

ApplicationWindow {
    id: estatisticas
    visible: true
    width: 800
    height: 600
    title: "Estatisticas da simulação"

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
            max: 5
        }

        ValueAxis {
            id: y
            max: 15
        }

        SplineSeries {
            id:qtAntigenos
            name: "Antigenos"
            axisX: x
            axisY: y
        }
    }

    Timer{
        running: true
        interval: 1000
        repeat: true
        onTriggered: {
            if(x.max <= qtAntigenos.count) x.max++;
            qtAntigenos.append(qtAntigenos.count, Math.floor(Math.random()*15));
        }
    }

}
