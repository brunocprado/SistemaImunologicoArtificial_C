#include "comum.h"

Comum::Comum() : Celula(TIPO_CELULA::COMUM){

}

void Comum::loop(){
    return;
//    if(estado == ESTADO::INFECTADA) printf("INFECTADO %d",id);
}

Celula::ESTADO Comum::getEstado(){
    return estado;
}

void Comum::setEstado(Celula::ESTADO e){
    estado = e;
}

QString Comum::extra(){
    QJsonObject json;
    json.insert("estado",QVariant::fromValue(estado).value<QString>());

    QJsonDocument tmp(json);
    return tmp.toJson();
}
