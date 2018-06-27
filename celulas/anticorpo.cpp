#include "anticorpo.h"

Anticorpo::Anticorpo(double x,double y,Virus* v) : Celula(TIPO_CELULA::ANTICORPO,x,y){
    virus = v;
}

void Anticorpo::loop(){
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
