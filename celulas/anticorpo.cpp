#include "sistemaimunologico.h"
#include "celulas/anticorpo.h"
#include "celulas/patogeno.h"

Anticorpo::Anticorpo(double x,double y,Virus* v) : Celula(TIPO_CELULA::ANTICORPO,x,y){
    virus = v;
}

void Anticorpo::loop(){

    envelhece();

    QList<Celula*>* tmp = SistemaImunologico::getInstancia()->getCelulas();
    for (int i = 0; i < tmp->length(); i++){
        Celula* celula = tmp->at(i);

        if(celula->getTipo() != TIPO_CELULA::PATOGENO) continue;

        Patogeno* tmp = static_cast<Patogeno*>(celula);
        if(calculaDistancia(celula) <= 15 && celula->getEstado() != ESTADO::SUPRIMIDA && tmp->getVirus() == virus){
            tmp->setEstado(ESTADO::SUPRIMIDA);
        }
    }

    //TODO REMOVE

    moveRand(4);
}

QString Anticorpo::extra(){
    QJsonObject json;
    json.insert("epitopo",virus->getEpitopo());
    json.insert("tempo de vida", QString().sprintf("%.2g dia(s)",(double) tempoVida/200));

    QJsonDocument tmp(json);
    return tmp.toJson();
}

Virus* Anticorpo::getVirus(){
    return virus;
}
