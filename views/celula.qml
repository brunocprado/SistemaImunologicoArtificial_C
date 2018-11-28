import QtQuick 2.12

Image {
    property QtObject celula

    visible: true
    width: 10
    height: 10

    transformOrigin: Item.Center

    x: celula.x
    y: celula.y

    MouseArea{
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
        property QtObject tooltip
        onClicked: {
            if(tooltip) { tooltip.visible = true; return; }
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
