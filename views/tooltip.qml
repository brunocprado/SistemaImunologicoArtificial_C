import QtQuick 2.10
import QtQuick.Controls 2.3

ToolTip {
    property int id: 0
    parent: parent
    visible: true
    width: 200
    height: 120
    Text{
        color: "#fff"
        text: "ID : " + id
    }
}
