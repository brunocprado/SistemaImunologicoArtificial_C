#include "compostoquimico.h"

CompostoQuimico::CompostoQuimico(TIPO_COMPOSTO tipo,int quantidade,Celula* emissor){
    this->tipo = tipo;
    this->emissor = emissor;
    x = emissor->getX();
    y = emissor->getY();
}

CompostoQuimico::TIPO_COMPOSTO CompostoQuimico::getTipo(){
    return tipo;
}
