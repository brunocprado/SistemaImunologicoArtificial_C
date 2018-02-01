#include "macrofago.h"

#include "sistemaimunologico.h"

Macrofago::Macrofago() : Celula(MACROFAGO){
    estado = REPOUSO;
}

void Macrofago::loop(){
    if(estado == FAGOCITANDO) return;

    QList<CompostoQuimico*>::iterator i;
    for (i = SistemaImunologico::getInstancia()->getQuimica()->getCompostos()->begin(); i != SistemaImunologico::getInstancia()->getQuimica()->getCompostos()->end(); ++i){
        if((*i)->getTipo() != CompostoQuimico::PAMP && (*i)->getTipo() != CompostoQuimico::CITOCINA) continue;

        CompostoQuimico* composto = (*i);

        if(composto->getEmissor() == nullptr) continue;
//        if(composto->getEmissor() == nullptr) continue; //REPENSAR SOBRE DPS !! if(composto.getEmissor() != null && !celulas.contains(composto.getEmissor())) continue;

        double dist = calculaDistancia(composto->x,composto->y);

        if(dist <= composto->getRaio() + 6){
//            printf("%f\n",dist);
            alvo = composto->getEmissor();
            tempoDetectado = QDateTime::currentDateTime();

//            if(dist <= 4) fagocita();
            if(estado == REPOUSO) { emiteQuimica(CompostoQuimico::CITOCINA,5);
                estado = ATIVO; }
            move(alvo);
        }
        break;
    }
}

Macrofago::ESTADO Macrofago::getEstado(){
    return this->estado;
}
