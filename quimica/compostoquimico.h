#ifndef COMPOSTOQUIMICO_H
#define COMPOSTOQUIMICO_H

#include "celulas/celula.h"

class CompostoQuimico{
public:
    enum TIPO_COMPOSTO {PAMP,HISTAMINA,CITOCINA,IL2,INTERLEUCINA1,TNFA};

    CompostoQuimico(TIPO_COMPOSTO,int quantidade,Celula* emissor);

    void aumentaRaio(short tam);

    TIPO_COMPOSTO getTipo();

private:
    TIPO_COMPOSTO tipo;
    Celula* emissor;
    int concetracao;
    int raio;
    int x,y;  //CENTRO

};

#endif // COMPOSTOQUIMICO_H
