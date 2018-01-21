import QtQuick 2.10
import QtQuick.Controls 2.3

ApplicationWindow {
    id: terminal
    visible: true
    width: 600
    height: 400
    x: 0
    y: 0
    color: "#000"
    title: qsTr("Terminal")

    Connections {
        target: sistema
        onEscreveLog:{
            log.text = log.text + texto + "\n";
        }
    }

    Flickable {
        id: flick
        anchors.bottomMargin: 50
        anchors.fill: parent

        contentHeight:  log.height
        Text {
            id: log
            color: "#bbb"
            padding: 10
            width: parent.width
            //            transform: Scale { yScale: -1; origin.y: texto.height/2 }
        }
        //                transform: Scale { yScale: -1; origin.y: flick.height/2 }
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

//        Row{
//            id: row
//            height: 50
//            padding: 5
//            layoutDirection: Qt.LeftToRight
//            spacing: 10
//            anchors.right: parent.right
//            anchors.rightMargin: 0
//            anchors.left: parent.left
//            anchors.leftMargin: 0

            TextField {
                id: textEdit
                text: qsTr("Text Edit")
                anchors.right: parent.right
                anchors.rightMargin: 105
                anchors.left: parent.left
                anchors.leftMargin: 5
                y: 5
                x: 5
                height: 40
                font.pixelSize: 12

            }

            Button {
                id: button
                width: 80
                height: 40
                y: 5
                text: qsTr("Button")
                autoRepeat: false
                autoExclusive: false
                checked: false
                checkable: false
                anchors.right: parent.right
                anchors.rightMargin: 15
            }

//        }
    }




}
