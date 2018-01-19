var componente;

var celulas = {};

function inicia(){
    componente =  Qt.createComponent("../celula.qml");
}

function cria(id,parente,imagem,x,y) {
    var tmp;

    switch(imagem){
        case 1: tmp = "macro.png"; break;
        case 2: tmp = "neutrofilo.png"; break;
        case 3: tmp = "Linfocito.png"; break;
    }

    tmp = "../imagens/" + tmp;

    celulas[id] = componente.createObject(parente,{"x":x,"y":y,"source":tmp});
}
