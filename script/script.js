var viewCelula, viewNovoSistema;
var celulas = {};

function inicia(){
    viewCelula = Qt.createComponent("../views/celula.qml");
    viewNovoSistema =Qt.createComponent("../views/celula.qml");
}

function cria(id,parente,imagem,x,y) {
    var tmp;

    switch(imagem){
        case 1: tmp = "macro.png"; break;
        case 2: tmp = "neutrofilo.png"; break;
        case 3: tmp = "Linfocito.png"; break;
    }

    tmp = "../imagens/" + tmp;

    celulas[id] = viewCelula.createObject(parente,{"x":x,"y":y,"source":tmp});
    celulas[id].tipo = 2;
}

function mudaVisibilidade(tipo,visivel){
    for(var i = 0;i<celulas.length;i++){
        if(celulas[i].tipo == tipo) celulas[i].visible = visivel;
    }
}

function novoSistema(){
    console.log("TTTT");
    viewNovoSistema.createObject();
}
