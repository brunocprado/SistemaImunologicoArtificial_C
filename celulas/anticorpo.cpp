#include "sistemaimunologico.h"
#include "celulas/anticorpo.h"
#include "celulas/patogeno.h"

Anticorpo::Anticorpo(double x,double y,Virus* v) : Celula(TIPO_CELULA::ANTICORPO,x,y){
    virus = v;
}

void Anticorpo::loop(){

    QList<Celula*>* tmp = SistemaImunologico::getInstancia()->getCelulas();
    for (int i = 0; i < tmp->length(); i++){
        Celula* celula = tmp->at(i);

        if(celula->getTipo() != TIPO_CELULA::PATOGENO) continue;

        Patogeno* tmp = static_cast<Patogeno*>(celula);
        if(calculaDistancia(celula) <= 10 && !tmp->suprimido && tmp->getVirus() == virus){
            tmp->suprimido = true;
        }
    }

    //TODO REMOVE

    moveRand(2);
}

int Anticorpo::getEpitopo(){
    return virus->getEpitopo();
}

QString Anticorpo::extra(){
    QJsonObject json;
    json.insert("epitopo",virus->getEpitopo());

    QJsonDocument tmp(json);
    return tmp.toJson();
}
