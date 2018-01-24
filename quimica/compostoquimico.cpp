#include "sistemaimunologico.h"
#include "compostoquimico.h"

CompostoQuimico::CompostoQuimico(TIPO_COMPOSTO tipo,int quantidade,Celula* emissor){
    this->tipo = tipo;
    this->emissor = emissor;
    x = emissor->x;
    y = emissor->y;
}

void CompostoQuimico::aumentaRaio(short tam){
    raio += tam;
    concetracao--;
    if(concetracao == 1){
        SistemaImunologico::getInstancia()->getQuimica()->remove(this);
    }
}

CompostoQuimico::TIPO_COMPOSTO CompostoQuimico::getTipo(){
    return tipo;
}
