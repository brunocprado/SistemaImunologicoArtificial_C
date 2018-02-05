#include "sistemaimunologico.h"
#include "compostoquimico.h"

static int contador = 0;

CompostoQuimico::CompostoQuimico(TIPO_COMPOSTO tipo,int quantidade,Celula* emissor){
    id=contador; contador++;
    this->tipo = tipo;
    this->emissor = emissor;
    concentracao = quantidade;
    raio = 10 * quantidade;
    x = emissor->x;
    y = emissor->y;
}

void CompostoQuimico::aumentaRaio(short tam){
    raio += tam;
    concentracao--;
    emit SistemaImunologico::getInstancia()->mudaComposto(id,tam,concentracao);
    if(concentracao == 1){
        SistemaImunologico::getInstancia()->getQuimica()->remove(this);
    }
}

CompostoQuimico::TIPO_COMPOSTO CompostoQuimico::getTipo(){
    return tipo;
}

short CompostoQuimico::getRaio(){
    return raio;
}

Celula* CompostoQuimico::getEmissor(){
    return emissor;
}

int CompostoQuimico::getId(){
    return id;
}
