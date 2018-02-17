#include "macrofago.h"

#include "sistemaimunologico.h"

Macrofago::Macrofago() : Celula(TIPO_CELULA::MACROFAGO){
    estado = ESTADO::REPOUSO;
}

void Macrofago::loop(){
    if(estado == ESTADO::FAGOCITANDO) return;

    if(alvo != nullptr){
        if(calculaDistancia(alvo) < 6){
//            alvo->remove();
//            alvo = nullptr;
        } else {
            move(alvo);
        }
        return;
    }

    for (int i = 0; i < SistemaImunologico::getCompostos()->length(); i++){
        CompostoQuimico *composto = SistemaImunologico::getCompostos()->at(i);

        if(composto->getTipo() != CompostoQuimico::PAMP && composto->getTipo() != CompostoQuimico::CITOCINA) continue;
        if(composto->getEmissor() == nullptr) continue; //REPENSAR SOBRE DPS !! if(composto.getEmissor() != null && !celulas.contains(composto.getEmissor())) continue;

        double dist = calculaDistancia(composto->x,composto->y);
        if(dist <= composto->getRaio() + 5){
            alvo = composto->getEmissor();
            tempoDetectado = QDateTime::currentDateTime();

//            if(dist <= 4) fagocita();
            if(estado == ESTADO::REPOUSO) {
                emiteQuimica(CompostoQuimico::CITOCINA,10);
                estado = ESTADO::ATIVO;
            }
            move(alvo);
            break;
        }
    }

    if(alvo == nullptr) move(x + (rand() % 4 - 1),y + (rand() % 4 - 1));

}

Macrofago::ESTADO Macrofago::getEstado(){
    return this->estado;
}

QString Macrofago::extra(){
    QJsonObject json;
    json.insert("estado",QVariant::fromValue(estado).value<QString>());
    if(alvo != nullptr) json.insert("alvo",alvo->id);

    QJsonDocument tmp(json);
    return tmp.toJson();
}
