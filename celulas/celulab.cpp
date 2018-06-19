#include "celulab.h"
#include "sistemaimunologico.h"

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

    //VOU CONSIDERAR UM RAIO de 10 //TODO


    double maisprox = INT16_MAX;
    double dist = 0;

    QList<Celula*>* tmp = SistemaImunologico::getInstancia()->getCelulas();
    for (int i = 0; i < tmp->length(); i++){
        Celula* celula = tmp->at(i);

        if(celula->getTipo() != TIPO_CELULA::PATOGENO) continue;

        dist = calculaDistancia(celula);
        if(maisprox > dist){
            maisprox = dist;
            alvo = static_cast<Patogeno*>(celula);
        }
    }
    if(maisprox <= 10){
        virus = alvo->getVirus();


    }

    moveRand();

}

void CelulaB::produzAnticorpo(){

}

Virus* CelulaB::getVirus(){
    return virus;
}

//CelulaB::ESTADO CelulaB::getEstado(){
//    return estado;
//}
