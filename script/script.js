var viewCelula, viewComposto, viewEstatisticas, estatisticaGerais;

var exibeQuimica = true;

var celulas = {};
var compostos = {};

//enum class TIPO_CELULA {COMUM,PATOGENO,MACROFAGO,NEUTROFILO,LINFOCITO,CELULA_B,ANTICORPO};

var tipoCelula = {
    "COMUM" : 0,
    "PATOGENO" : 1,
    "MACROFAGO" : 2,
    "NEUTROFILO" : 3
}

function inicia(){
    viewCelula = Qt.createComponent("../views/celula.qml");
    viewComposto = Qt.createComponent("../views/composto.qml");
    viewEstatisticas = Qt.createComponent("../views/estatisticas.qml");
    estatisticaGerais = Qt.createComponent("../views/estatisticasGerais.qml").createObject(janela,{});
}

function cria(parente,celula) {
    var tmp;

    switch(celula.tipo){
        case 0: tmp = "celula.png"; break;
        case 1: tmp = "opcoes.png"; break;
        case 2: tmp = "macro.png"; break;
        case 3: tmp = "neutrofilo.png"; break;
        case 4: tmp = "Linfocito.png"; break;
    }

    tmp = "../imagens/" + tmp;

    celulas[celula.id] = viewCelula.createObject(parente,{"celula":celula,"source":tmp});
}

function addComposto(parente,id,cor,raio,x,y){
    switch(cor){
        case 0: cor = "#fff"; break;
        case 1: cor = "#faa"; break;
        case 2: cor = "#afa"; break;
        case 3: cor = "#aaa"; break;
    }
    compostos[id] = viewComposto.createObject(parente,{"x":x-raio,"y":y-raio,"width":raio*2,"color":cor,"visible":exibeQuimica});
}

function mudaVisibilidade(tipo){
    for(var id in celulas){
        if(celulas[id].celula.tipo === tipo)
            celulas[id].visible = !celulas[id].visible;
    }
}

function mudaVisibilidadeQuimica(){
    exibeQuimica = !exibeQuimica;
    for(var id in compostos){
        compostos[id].visible = exibeQuimica;
    }
}
