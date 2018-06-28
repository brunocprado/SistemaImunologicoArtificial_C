import QtQuick 2.11

Image {
    property var celula

    visible: true
    width: 10
    height: 10

    transformOrigin: Item.Center
    rotation: 0

    x: celula.x - 5
    y: celula.y - 5

    function atualizaPos(){
        x = celula.x - 5;
        y = celula.y - 5;
    }

    MouseArea{
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        property var tooltip: 0
        onClicked: {
            if(tooltip !== 0) { tooltip.visible = true; return; }
            var t;
            switch(celula.tipo){
                case 0: t = "epitelial"; break;
                case 1: t = "patógeno"; break;
                case 2: t = "macrófago"; break;
                case 3: t = "neutrófilo"; break;
                case 4: t = "linfócito"; break;
                case 5: t = "Célula B"; break;
                case 6: t = "Anticorpo"; break;
            }

            tooltip = Qt.createComponent("tooltip.qml").createObject(this,{"celula": celula,"tipo": t,"imagem":parent.source});
        }
    }
}
