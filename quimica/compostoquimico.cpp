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

short CompostoQuimico::aumentaRaio(short tam){
    //if(this == 0x0) {  return;}
    //try {
        raio += tam;
    //}/* catch (...) {
        SistemaImunologico::getInstancia()->getQuimica()->remove(this);
        //re/*t*/urn;
    //}*/

    concentracao--;
    emit SistemaImunologico::getInstancia()->mudaComposto(id,tam,concentracao);
    if(concentracao == 1){
//return 1;
        SistemaImunologico::getInstancia()->getQuimica()->remove(this);
        return 1;
    } else { return 0; }
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
