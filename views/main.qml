import QtQuick 2.10
import QtQuick.Controls 2.3
import QtQuick.Controls.Material 2.3
import QtQuick.Window 2.3

import "../script/script.js" as Script

ApplicationWindow {
    id: janela
    visible: true
    width: 1280
    height: 720
    minimumHeight: 700
    minimumWidth: 1000
    color: "#c6c6c6"
    title: (temporizador.segundos != 0) ? "Sistema imunológico artificial C++ - Tempo de execução : " + temporizador.segundos + " segundos  |  " + (temporizador.segundos/6).toFixed(2) + " dia(s)  " + versao : "Sistema imunológico artificial C++  " + versao;

    property string versao : "|  Versão  :  " + sistema.versao_git() + "  Alpha"
    property var quantidade_celulas : [0,0,0,0,0,0,0]

    Shortcut {
        sequences: ["Ctrl++","A"]
        onActivated: celulas.scale += 0.2
    }

    Shortcut {
        sequences: ["Ctrl+-","S"]
        onActivated: if(celulas.scale > 1) celulas.scale -= 0.2
    }

    Shortcut {
        sequence: "F1"
        onActivated: {
            var tmp = Qt.createComponent("../views/sobre.qml");
            tmp.createObject(janela,{});
        }
    }

    Shortcut{
        sequence: "Ctrl+N"
        onActivated: {
            novoSistema();
        }
    }

    function novoSistema(){
        if(Script.viewNovoSistema) Script.viewNovoSistema.destroy();
        Script.viewNovoSistema = Qt.createComponent("novoSistema.qml").createObject(janela,{});
    }

    Component.onCompleted: {
        Script.inicia();
        setX(Screen.width / 2 - width / 2);
        setY(Screen.height / 2 - height / 2);
    }

    Component.onDestruction:  {
        sistema.encerra();
        Qt.quit();
    }

    onWidthChanged: {
        if(width > 1600 && celulas.scale == 1){
            celulas.scale = width/1600;
        }
    }

    onHeightChanged: {
        if(height > 850) logoBranca.visible = true; else logoBranca.visible = false;
    }

    Connections {
        target: sistema
        onAdicionaCelula: {
            Script.cria(celulas,celula);
            janela.quantidade_celulas[celula.tipo] ++;
        }
        onMovimentaCelula: {
            if(Script.celulas[id] === undefined) return;
            Script.celulas[id].atualizaPos();
        }
        onEliminaCelula: {
            if(Script.celulas[id] === undefined) return;
            janela.quantidade_celulas[Script.celulas[id].celula.tipo] --;
            Script.celulas[id].destroy();
            delete Script.celulas[id];
        }
        onAdicionaComposto: {
            Script.addComposto(celulas,id,tipo,raio,x,y);
        }
        onMudaComposto: {
            Script.compostos[id].x -= varRaio;
            Script.compostos[id].y -= varRaio;
            Script.compostos[id].width += varRaio * 2;
            Script.compostos[id].opacity -= 0.05;
        }
        onEliminaComposto: {
            if(Script.compostos[id] === undefined) return;
            Script.compostos[id].destroy();
            delete Script.compostos[id];
        }
        onAddVirus: {
            temporizador.running = true;
            var tmp = Script.viewEstatisticas.createObject(janela,{"virus":virus});
            menuEstatisticas.addItem(menuLayout.createObject(menuEstatisticas,{"virus":tmp,"text":virus.identificador}));
        }
        onReseta: {
            temporizador.segundos = 0;
            temporizador.restart(); temporizador.stop();
        }
    }

    Timer{
        id: temporizador
        running: false
        repeat: true
        interval: 1000
        property int segundos: 0
        onTriggered: {
            segundos++;
        }
    }

    Image {
        id: fundo
        anchors.fill: parent
        fillMode: Image.Stretch
        source: "../imagens/blood.jpg"

        Flickable{
            contentWidth: 1600 * celulas.scale
            contentHeight: 900 * celulas.scale
            anchors.fill: parent

            Frame{
                id: celulas
                transformOrigin: Item.TopLeft
                anchors.fill: parent
                scale: 1.2
            }
        }
    }

    menuBar: MenuBar {
        id: menu
//        Material.theme: Material.Dark
        Menu {
            title: "Novo"
            MenuItem {
                text: "Sistema        [Ctrl+N]"
                onClicked: {
                    novoSistema();
                }
            }

            MenuItem {
                text: "Patogeno      [Ctrl+P]"
                onClicked: {
                    sistema.addPatogeno();
                }
            }
        }

        MenuBarItem{
            text: "Opções"
            onClicked: {
                (opcoes.visible) ? opcoes.close() : opcoes.open();
            }
        }

        MenuBarItem{
            id: menuPausar
            text: "Pausar"
            onClicked:{
                if(menuPausar.text == "Pausar"){
                    menuPausar.text = "Resumir";
                    sistema.pausar();
                    temporizador.running = false;
                } else {
                    menuPausar.text = "Pausar";
                    sistema.resumir();
                    if(janela.quantidade_celulas[1] > 0) temporizador.running = true;
                }
            }
        }

        Menu{
            id: menuEstatisticas
            title: "Estatísticas"

            MenuItem{
                text: "Estatisticas gerais"
                onClicked: {
                    Script.estatisticaGerais.visible = true;
                }
            }

            Component {
                id: menuLayout
                MenuItem {
                    property var virus
                    onClicked: {
                        virus.visible = true;
                    }
                }
            }
        }

        MenuBarItem{
            text: "Sobre"
            onClicked: {
                var tmp = Qt.createComponent("../views/sobre.qml");
                tmp.createObject(janela,{});
            }
        }
    }

    Drawer {
        id: opcoes
        width: 320
        height: janela.height
        y: menu.height
        Material.foreground: "#fff"
        Material.accent: Material.Green
        background: Rectangle {
            color: "#8f4f4f"
            Rectangle {
                x: parent.width - 1
                width: 1
                height: parent.height
                color: "#555"
            }
        }

        Image {
            id: logoBranca
            visible: false
            source: "../imagens/logoBranca.png"
            opacity: 0.2
            x: 57
            y: parent.height - 250
            width: 170
            height: 180
        }

        Column {
            id: column
            y:10
            width: 300
            padding: 20
            height: parent.height
            spacing: 30

            Row {
                width: 260
                height: 60
                Column {
                    width: 182
                    spacing: 10

                    Text {
                        color: "#ffffff"
                        text: qsTr("CAMADA QUÍMICA")
                        font.bold: true
                        font.family: "Roboto"
                        font.pixelSize: 15
                    }

                    Text {
                        width: 200
                        color: "#ffffff"
                        text: qsTr("Exibe emissão de compostos químicos")
                        wrapMode: Text.WordWrap
                        font.pixelSize: 12
                    }
                }
                Switch {
                    height: 30
                    text: qsTr("Sim")
                    checked: true
                    onToggled: {
                        Script.mudaVisibilidadeQuimica();
                    }
                }
            }

            //DEBUG
            Row {
                width: 260
                height: 60
                Column {
                    width: 182
                    spacing: 10
                    Text {
                        color: "#ffffff"
                        text: qsTr("DEBUG")
                        font.family: "Roboto"
                        font.bold: true
                        font.pixelSize: 15
                    }

                    Text {
                        width: 200
                        color: "#ffffff"
                        text: qsTr("Imprime informações de desenvolvedor")
                        wrapMode: Text.WordWrap
                        font.pixelSize: 12
                    }
                }
                Switch {
                    height: 30
                    text: qsTr("Sim")
                    checked: false
                    onToggled: {
                        var tmp = sistema.getVirus(0);
                        console.log(tmp);
                        console.log(tmp.getQuantidade());
                    }
                }
            }

            Rectangle {
                width: 260
                height: 2
                color: "#ffffff"
            }

            //TERCEIRO SLIDER

            Row {
                width: 260
                height: 30
                Text {
                    width: 180
                    height: 25
                    color: "#ffffff"
                    text: qsTr("EXIBIR MACROFAGOS")
                    font.family: "Roboto"
                    topPadding: 5
                    font.bold: true
                    font.pixelSize: 15
                }
                Switch {
                    x: 0
                    height: 30
                    text: qsTr("Sim")
                    checked: true
                    onClicked: {
                        Script.mudaVisibilidade(2);
                    }
                }
            }

            //QUARTO SLIDER

            Row {
                width: 260
                height: 30
                Text {
                    width: 180
                    height: 25
                    color: "#ffffff"
                    text: qsTr("EXIBIR LINFOCITOS")
                    font.family: "Roboto"
                    topPadding: 5
                    font.bold: true
                    font.pixelSize: 15
                }
                Switch {
                    height: 30
                    text: qsTr("Sim")
                    checked: true
                    onClicked: {
                        Script.mudaVisibilidade(4);
                    }
                }
            }

            //QUINTO SLIDER

            Row {
                width: 260
                height: 30
                Text {
                    width: 180
                    height: 25
                    color: "#ffffff"
                    text: qsTr("EXIBIR NEUTROFILOS")
                    font.family: "Roboto"
                    topPadding: 5
                    font.bold: true
                    font.pixelSize: 15
                }
                Switch {
                    height: 30
                    text: qsTr("Sim")
                    checked: true
                    onClicked: {
                        Script.mudaVisibilidade(3);
                    }
                }
            }

            //PATOGENOS

            Row {
                width: 260
                height: 30
                Text {
                    width: 180
                    height: 25
                    color: "#ffffff"
                    text: qsTr("EXIBIR PATOGENOS")
                    font.family: "Roboto"
                    topPadding: 5
                    font.bold: true
                    font.pixelSize: 15
                }
                Switch {
                    height: 30
                    text: qsTr("Sim")
                    checked: true
                    onClicked: {
                        Script.mudaVisibilidade(1);
                    }
                }
            }

            Rectangle {
                width: 260
                height: 2
                color: "#ffffff"
            }

            Column{
                width: 260
                height: 85
                spacing: 10

                Text {
                    color: "#ffffff"
                    text: qsTr("VELOCIDADE")
                    font.family: "Roboto"
                    font.pixelSize: 15
                    font.bold: true
                }

                Text {
                    color: "#ffffff"
                    text: qsTr("Muda velocidade da simulação")
                    font.pixelSize: 10
                }

                Slider {
                    id: slider
                    x: -5
                    width: 265
                    height: 35
                    live: true
                    from: 0
                    value: 1
                    to:2
//                    stepSize: 0.2
//                    snapMode: Slider.SnapOnRelease
                    ToolTip {
                        parent: slider.handle
                        visible: slider.pressed
                        text: slider.value.toFixed(1) + " x"
                    }
                    onValueChanged: {
//                        console.info((value < 1) ? 2 - value : 1/value);
                        sistema.mudaVelocidade((value < 1) ? 2 - value : 1/value);
                    }
                }
            }
        }
    }
}
