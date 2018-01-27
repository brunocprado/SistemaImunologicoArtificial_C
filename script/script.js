var viewCelula, viewComposto, viewNovoSistema, viewSobre;
var celulas = [];
var compostos = [];

function inicia(){
    viewCelula = Qt.createComponent("../views/celula.qml");
    viewComposto = Qt.createComponent("../views/composto.qml");
    viewNovoSistema =Qt.createComponent("../views/celula.qml");
    viewSobre = Qt.createComponent("../views/sobre.qml");
}

function cria(id,parente,imagem,x,y) {
    var tmp;

    switch(imagem){
        case 1: tmp = "anti.png"; break;
        case 2: tmp = "macro.png"; break;
        case 3: tmp = "neutrofilo.png"; break;
        case 4: tmp = "Linfocito.png"; break;
    }

    tmp = "../imagens/" + tmp;

    celulas.push(viewCelula.createObject(parente,{"id":id,"tipo":imagem,"x":x,"y":y,"source":tmp}));
}

function addComposto(id,tipo,x,y){
    compostos.push(viewComposto.createObject(celulas,{"x":x,"y":y}));
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
