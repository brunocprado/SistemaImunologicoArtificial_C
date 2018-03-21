import QtQuick 2.10
import QtQuick.Controls 2.3
import QtCharts 2.2
import QtQuick.Window 2.3

ApplicationWindow {
    title: "Estatísticas Gerais"
    width: 900
    height: 500
    visible: false

    Timer{
        running: parent.visible
        repeat: true
        interval: 2000
        onTriggered: {
            if(x.max <= qtLinfocitos.count) x.max++;
            qtMacrofagos.append(qtMacrofagos.count,janela.quantidade_celulas[2]);
            qtLinfocitos.append(qtLinfocitos.count, janela.quantidade_celulas[4]);
        }
    }

    ChartView {
        title: "Estatisticas"
        anchors.fill: parent
        antialiasing: true
        dropShadowEnabled: true
        theme: ChartView.ChartThemeDark

        ValueAxis {
            id: x
            titleText: "Tempo"
            max: 5
        }

        ValueAxis {
            id: y
            titleText: "Quantidade"
            max: 300
        }

        SplineSeries {
            id:qtMacrofagos
            name: "Macrofagos"
            axisX: x
            axisY: y
        }

        SplineSeries {
            id:qtLinfocitos
            name: "Linfocitos"
            axisX: x
            axisY: y
        }
    }

}
