#include "comum.h"

Comum::Comum() : Celula(TIPO_CELULA::COMUM){

}

void Comum::loop(){
    moveRand();
    return;
//    if(estado == ESTADO::INFECTADA) printf("INFECTADO %d",id);
}

QString Comum::extra(){
    QJsonObject json;
    json.insert("estado",QVariant::fromValue(estado).value<QString>());
    if(virus) json.insert("virus",virus->getIdentificador());

    QJsonDocument tmp(json);
    return tmp.toJson();
}
