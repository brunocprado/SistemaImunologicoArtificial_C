import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Window 2.3

ApplicationWindow {
    id: sobre
    title: "Sobre"
    visible: true
    flags: Qt.WindowStaysOnTopHint
    width: 410
    height: 220
    minimumHeight: 220
    maximumHeight: 220
    minimumWidth: 410
    maximumWidth: 410

    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }

    Image {
        x: 10
        y: 10
        width: 100
        height: 100
        source: "../imagens/ufrrjLogo.png"
    }

    Text {
        font.pixelSize: 20
        x: 121
        y: 10
        text: qsTr("Sistema Imunológico Artificial")
        font.family: "Arial"
    }

    Text {
        x: 121
        y: 52
        text: qsTr("Bruno César do Prado Lopes")
        font.bold: true
        font.pixelSize: 14
    }

    Text {
        x: 121
        y: 75
        text: qsTr("Graduando em Sistemas de Informação UFRRJ")
        font.pixelSize: 12
    }

    Text {
        x: 121
        y: 95
        color: "#085bad"
        text: qsTr("http://github.com/brunocprado")
        font.pixelSize: 11
    }

    Text {
        x: 24
        y: 188
        text: qsTr("2016 - 2018")
        font.pixelSize: 12
    }

    Button {
        x: 322
        y: 178
        width: 77
        height: 34
        text: qsTr("OK")
        highlighted: false
        onClicked: {
            close();
        }
    }
}
