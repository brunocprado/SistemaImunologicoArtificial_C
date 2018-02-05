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
        animationDuration: 100
        animationOptions: ChartView.AllAnimations
        title: "Line"
        anchors.fill: parent
        antialiasing: true


        LineSeries {
            id:pieSeries
            name: "LineSeries"
            XYPoint { x: 0; y: 0 }
            XYPoint { x: 1; y: 2.1 }
            XYPoint { x: 2; y: 3.3 }
        }
    }

    Timer{
        running: true
        interval: 1000
        repeat: true
        onTriggered: {
            pieSeries.append(pieSeries.count + 1, 4.0);
//            chart.r
        }
    }

}
