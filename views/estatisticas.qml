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
    height: 400
    minimumHeight: 380
    title: "Estatisticas da simulação [ " + virus.identificador + " ]"

//    color: "transparent"
//    flags: Qt.Popup //TODO IF
//    x: janela.x + janela.width - 550
//    y: janela.y + 50

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
                if(!temporizacaoGrafico.running) temporizacaoGrafico.running = parent.visible;
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
            max: 40
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
        id: temporizacaoGrafico
        running: parent.visible
        interval: 100
        repeat: true
        onTriggered: {
            if(xx.max <= qtAntigenos.count) xx.max++;
            if(yy.max <= virus.quantidade || yy.max <= virus.anticorpos) yy.max+=2;

            qtAntigenos.append(qtAntigenos.count, virus.quantidade);
            qtAnticorpos.append(qtAnticorpos.count, virus.anticorpos);
            if(virus.quantidade <= 0 && virus.anticorpos <= 0) running = false;
        }
    }
}
