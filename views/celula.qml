import QtQuick 2.10

Image {
    property var celula

    visible: true
    width: 10
    height: 10

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
            var tmp = Qt.createComponent("tooltip.qml");
            var t;
            switch(celula.tipo){
                case 0: t = "epitelial"; break;
                case 1: t = "patógeno"; break;
                case 2: t = "macrófago"; break;
                case 3: t = "neutrófilo"; break;
                case 4: t = "linfócito"; break;
            }

            tooltip = tmp.createObject(this,{"celula": celula,"tipo": t,"imagem":parent.source});
        }
    }
}
