import QtQuick 2.10
import QtQuick.Controls 2.3

ApplicationWindow {
    id: terminal
    visible: true
    width: 600
    height: 400
    minimumWidth: 500
    minimumHeight: 320
    x: 0
    y: 0
    color: "#000"
    title: qsTr("Terminal")

    Connections {
        target: sistema
        onEscreveLog:{
            if(cor){
                log.text += '<font color="' + cor + '">' + texto + '</font>' + "<br>";
            } else {
                log.text += texto + "<br>";
            }
        }
    }

    Flickable {
        id: flick
        anchors.bottomMargin: 40
        anchors.fill: parent
        contentHeight:  log.height
        Text {
            id: log
            color: "#bbb"
            padding: 10
            font.pixelSize: 12
            width: parent.width
            transform: Scale { yScale: -1; origin.y: log.height/2 }
        }
        transform: Scale { yScale: -1; origin.y: flick.height/2 }
    }

    Rectangle {
        id: rectangle
        y: 353
        height: 50
        color: "#ccc"
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        TextField {
            id: txtComando
            text: ""
            placeholderText: "Comando"
            anchors.right: parent.right
            anchors.rightMargin: 105
            anchors.left: parent.left
            anchors.leftMargin: 10
            y: 5
            height: 40
            font.pixelSize: 12
        }

        Button {
            id: btnComando
            width: 80
            height: 40
            y: 5
            text: qsTr("OK")
            autoRepeat: false
            autoExclusive: false
            checked: false
            checkable: false
            anchors.right: parent.right
            anchors.rightMargin: 15
        }
    }
}
