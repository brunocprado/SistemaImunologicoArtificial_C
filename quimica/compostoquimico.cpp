#include "compostoquimico.h"

CompostoQuimico::CompostoQuimico(TIPO_COMPOSTO tipo,int quantidade,Celula* emissor){
    this->tipo = tipo;
    this->emissor = emissor;
    x = emissor->x;
    y = emissor->y;
}

CompostoQuimico::TIPO_COMPOSTO CompostoQuimico::getTipo(){
    return tipo;
}
