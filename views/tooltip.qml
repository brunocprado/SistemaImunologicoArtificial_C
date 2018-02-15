import QtQuick 2.10
import QtQuick.Controls 2.3

ToolTip {
    property string tipo: ""
    property string imagem: ""
    property var celula
    property var extra : ""

    parent: parent
    visible: true
    width: 220
    height: 120

    Component.onCompleted: {
        atualizaInfo();
    }

    function atualizaInfo(){
        txtPosicao.text = "Posição : " + celula.x.toFixed(2) + " x " + celula.y.toFixed(2)
        if(celula.extra !== "") extra = JSON.parse(celula.extra); else return;
        txtExtra.text = "";
        for(var chave in extra){
            txtExtra.text += chave + " : " + extra[chave] + "\n";
        }
    }

    Timer{
        running: parent.visible
        repeat: true
        interval: 500
        onTriggered: {
            atualizaInfo();
        }
    }

    Text{
        color: "#fff"
        width: parent.width
        font.pixelSize: 18
        text: tipo.toUpperCase()
        horizontalAlignment: Text.AlignHCenter
    }

    Image {
        y: 35
        visible: true
        width: 60
        height: 60
        source: imagem
    }

    Column{
        x: 80
        y: 35
        spacing: 5
        Text{
            font.pixelSize: 10
            color: "#fff"
            text: "ID : " + celula.id
        }

        Text{
            id: txtPosicao
            font.pixelSize: 10
            color: "#fff"
        }

        Text{
            id: txtExtra
            font.pixelSize: 10
            color: "#fff"
            font.capitalization: Font.Capitalize
            lineHeight: 1.4
        }
    }
}
