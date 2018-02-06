import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3

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
        onAddParametro:{
            listaParametros.append({"name": parametro});
        }
    }

    Flickable {
        id: flick
        anchors.bottomMargin: 40
        anchors.fill: parent
        contentHeight:  log.height
        Text {
            id: log
            color: "#ccc"
            padding: 10
            font.pixelSize: 12
            lineHeight: 1.4
            width: parent.width
            transform: Scale { yScale: -1; origin.y: log.height/2 }
        }
        transform: Scale { yScale: -1; origin.y: flick.height/2 }
    }

    Rectangle {
        y: 353
        height: 50
        color: "#eee"
        anchors.right: parent.right
        anchors.left: parent.left
        anchors.bottom: parent.bottom

        ComboBox {
            id: txtComando
//            editText: editText.toUpperCase()
            currentIndex: -1
            y: 5
            height: 40
            font.pixelSize: 12
            editable: true
            model: ListModel{
                id: listaParametros
            }

            anchors.right: parent.right
            anchors.rightMargin: 105
            anchors.left: parent.left
            anchors.leftMargin: 10

            Shortcut{
                sequence: "Enter"
                onActivated: {
                    btnComando.executaCmd();
                }
            }
        }

        Button {
            id: btnComando
            width: 80
            height: 40
            y: 5
            text: qsTr("OK")
            anchors.right: parent.right
            anchors.rightMargin: 15
            Material.background: Material.Green
            highlighted: true

            function executaCmd(){
                var tmp = txtComando.editText.split(" ");
                if(tmp.length < 2) return;
                sistema.mudaParametro(tmp[0],tmp[1]);
                txtComando.editText = ""; txtComando.currentIndex = -1;
            }

            onClicked: {
                executaCmd();
            }
        }
    }
}
