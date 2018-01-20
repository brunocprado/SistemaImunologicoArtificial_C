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



    Pane {
        id: pane
        x: 60
        y: 71
        width: 200
        height: 200
    }


}
