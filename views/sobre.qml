import QtQuick 2.11
import QtQuick.Controls 2.3
import QtQuick.Window 2.3
import QtQuick.Controls.Material 2.3

ApplicationWindow {
    id: sobre
    title: "Sobre"
    visible: true
    flags: Qt.WindowStaysOnTopHint | Qt.Dialog
    width: 410
    height: 220
    minimumHeight: 220
    maximumHeight: 220
    minimumWidth: 410
    maximumWidth: 410

//    opacity: 0.9

    modality: Qt.ApplicationModal

    Component.onCompleted: {
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }

    Image {
        x: 8
        y: 40
        width: 100
        height: 100
        source: "../imagens/ufrrjLogo.png"
    }

    Text {
        font.pixelSize: 20
        x: 8
        y: 7
        width: 391
        height: 23
        text: qsTr("Sistema Imunológico Artificial")
        horizontalAlignment: Text.AlignHCenter
        font.family: "Arial"
    }

    Text {
        x: 121
        y: 62
        text: qsTr("Bruno César do Prado Lopes")
        font.bold: true
        font.pixelSize: 14
    }

    Text {
        x: 121
        y: 85
        text: qsTr("Graduando em Sistemas de Informação UFRRJ")
        font.pixelSize: 12
    }

    Text {
        x: 121
        y: 105
        color: "#085bad"
        text: "<a href='http://github.com/brunocprado'>http://github.com/brunocprado</a>"
        onLinkActivated: Qt.openUrlExternally(link)
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
        Material.background: "#891717"
        Material.foreground: "#fff"

        onClicked: {
            close();
        }
    }
}
