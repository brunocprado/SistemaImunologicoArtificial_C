import QtQuick 2.10
import QtQuick.Controls 2.3

Image {
    property int id: 0
    property int tipo: 0
    property bool visivel: true

    visible: visivel
    width: 10
    height: 10
    MouseArea{
        anchors.fill: parent
        cursorShape: Qt.ClosedHandCursor
        onClicked: {
            var tmp = Qt.createComponent("tooltip.qml");
            tmp.createObject(this,{"id":id});
        }
    }
}
