#include "macrofago.h"

#include "sistemaimunologico.h"

Macrofago::Macrofago() : Celula(MACROFAGO){
    estado = REPOUSO;
}

void Macrofago::loop(){
    if(estado == FAGOCITANDO) return;

//    QList<CompostoQuimico*>::iterator i;
    for (int i = 0; i < SistemaImunologico::getCompostos()->length(); i++){
        CompostoQuimico *composto = SistemaImunologico::getCompostos()->at(i);
        if(composto->getTipo() != CompostoQuimico::PAMP && composto->getTipo() != CompostoQuimico::CITOCINA) continue;

        if(composto->getEmissor() == nullptr) continue;
//        if(composto->getEmissor() == nullptr) continue; //REPENSAR SOBRE DPS !! if(composto.getEmissor() != null && !celulas.contains(composto.getEmissor())) continue;

        double dist = calculaDistancia(composto->x,composto->y);

        if(dist <= composto->getRaio() + 5){
//            printf("%f\n",dist);
            alvo = composto->getEmissor();
            tempoDetectado = QDateTime::currentDateTime();

//            if(dist <= 4) fagocita();
            if(estado == REPOUSO) { emiteQuimica(CompostoQuimico::CITOCINA,6);
                estado = ATIVO; }
            move(alvo);
        }
        break;
    }
}

Macrofago::ESTADO Macrofago::getEstado(){
    return this->estado;
}
