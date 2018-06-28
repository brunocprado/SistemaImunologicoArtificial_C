import QtQuick 2.11
import QtQuick.Controls 2.3
import QtCharts 2.2
import QtQuick.Window 2.3
import QtQuick.Controls.Material 2.3

ApplicationWindow {
    property var virus

    id: estatisticas
    visible: true
    width: 800
    minimumWidth: 540
    height: 600
    minimumHeight: 380
    title: "Estatisticas da simulação [ " + virus.identificador + " ]"
    color: "#8f4f4f"

    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }

    ChartView {
        id: chartView
        height: 550
        anchors.fill: parent
        title: "Estatisticas"
        antialiasing: true
        dropShadowEnabled: true

        Button {
            id: btnNovaEntrada
            x: 633
            y: 23
            width: 126
            height: 47
            text: qsTr("Nova entrada")
            anchors.right: parent.right
            anchors.rightMargin: 41
            Material.background: Material.BlueGrey
            highlighted: true

            onClicked: {
                sistema.addPatogeno(virus);
            }
        }

        ValueAxis {
            id: xx
            titleText: "Tempo"
            max: 5
            labelsVisible: false
        }

        ValueAxis {
            id: yy
            titleText: "Quantidade"
            max: 20
        }

        SplineSeries {
            id:qtAntigenos
            name: "Antigenos"
            axisX: xx
            axisY: yy
        }

        SplineSeries {
            id:qtAnticorpos
            name: "Anticorpos"
            axisX: xx
            axisY: yy
        }
    }

    Timer{
        running: parent.visible
        interval: 250
        repeat: true
        onTriggered: {
            if(xx.max <= qtAntigenos.count) xx.max++;
            qtAntigenos.append(qtAntigenos.count, virus.quantidade);
            qtAnticorpos.append(qtAnticorpos.count, virus.anticorpos);
            if(virus.quantidade <= 0) running = false;
        }
    }
}
