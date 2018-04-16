#include "macrofago.h"
#include "patogeno.h"

#include "sistemaimunologico.h"

Macrofago::Macrofago() : Celula(TIPO_CELULA::MACROFAGO){
    estado = ESTADO::REPOUSO;
}

void Macrofago::loop(){
    envelhece();

    if(qrand() % 450 == 1){
        Macrofago *tmp = new Macrofago();
        tmp->moveToThread(SistemaImunologico::getThread());
        SistemaImunologico::getInstancia()->renderizaCelula(tmp);
    }

    if(estado == ESTADO::FAGOCITANDO) return;

    if(alvo != nullptr){
        if(calculaDistancia(alvo) < 6){
            if(SistemaImunologico::getInstancia()->getCelulas()->contains(alvo)) alvo->remove();
            alvo = nullptr;
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

            Patogeno* tmp = (Patogeno*)alvo;
//            tmp->getVirus()->addTemporizacao(tempoDetectado.toSecsSinceEpoch() - tmp->getInicio().toSecsSinceEpoch());

//            if(dist <= 4) fagocita();
            if(estado == ESTADO::REPOUSO) {
                emiteQuimica(CompostoQuimico::CITOCINA,10);
                estado = ESTADO::ATIVO;
            }
            move(alvo);
            break;
        }
    }

    if(alvo == nullptr) move(x + (qrand() % 4 - 1),y + (qrand() % 4 - 1));

}

Macrofago::ESTADO Macrofago::getEstado(){
    return this->estado;
}

QString Macrofago::extra(){
    QJsonObject json;
    json.insert("tempo de vida",QString("%1 dia(s)").arg((double)(tempoVida/200)));
    json.insert("estado",QVariant::fromValue(estado).value<QString>());
    if(alvo != nullptr) json.insert("alvo",alvo->id);

    QJsonDocument tmp(json);
    return tmp.toJson();
}
