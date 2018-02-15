#include "celulab.h"

CelulaB::CelulaB() : Celula(TIPO_CELULA::CELULA_B){

}

CelulaB::CelulaB(double x, double y) : Celula(TIPO_CELULA::CELULA_B,x,y){

}

void CelulaB::inicia(){
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(produzAnticorpo()));
    timer->start(600);
}

void CelulaB::loop(){
    //TODO
}

void CelulaB::produzAnticorpo(){

}

Virus* CelulaB::getVirus(){
    return virus;
}

CelulaB::ESTADO CelulaB::getEstado(){
    return estado;
}
