import QtQuick 2.10
import QtQuick.Controls 2.3

ApplicationWindow {
    id: novoSistema
    width: 500
    height: 320
    visible: false
    color: "#888"

    Component.onCompleted: {
        console.log("TESTE")
    }

    GroupBox {
        id: groupBox
        x: 13
        y: 13
        width: 200
        height: 200
        title: qsTr("Group Box")
    }

}
