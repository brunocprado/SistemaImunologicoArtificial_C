var viewCelula, viewComposto, viewNovoSistema, viewSobre;
var celulas = [];
var compostos = {};

var tipoCelula = {
    "NEUTROFILO" : 1,
    "MACROFAGO" : 2

}

function inicia(){
    viewCelula = Qt.createComponent("../views/celula.qml");
    viewComposto = Qt.createComponent("../views/composto.qml");
    viewNovoSistema =Qt.createComponent("../views/celula.qml");
    viewSobre = Qt.createComponent("../views/sobre.qml");
}

function cria(id,parente,imagem,x,y) {
    var tmp;

    switch(imagem){
        case 1: tmp = "neutrofilo.png"; break;
        case 2: tmp = "macro.png"; break;
        case 3: tmp = "neutrofilo.png"; break;
        case 4: tmp = "Linfocito.png"; break;
    }

    tmp = "../imagens/" + tmp;

    celulas[id] = viewCelula.createObject(parente,{"id":id,"tipo":imagem,"x":x,"y":y,"imagem":tmp});
}

function addComposto(parente,id,cor,raio,x,y){
    switch(cor){
        case 0: cor = "#fff"; break;
        case 1: cor = "#faa"; break;
        case 2: cor = "#afa"; break;
        case 3: cor = "#aaa"; break;
    }
    compostos[id] = viewComposto.createObject(parente,{"x":x-raio,"y":y-raio,"width":raio*2,"color":cor});
}

function mudaVisibilidade(tipo){
    for(var i = 0;i<celulas.length;i++){
        if(celulas[i].tipo === tipo)
            celulas[i].visible = !celulas[i].visible;
    }
}

function novoSistema(){
    viewNovoSistema.createObject();
}

function exibeSobre(){
    viewSobre.createObject(janela,{});
}
