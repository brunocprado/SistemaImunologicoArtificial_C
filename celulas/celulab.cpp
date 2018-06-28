#include "celulab.h"
#include "anticorpo.h"
#include "sistemaimunologico.h"

CelulaB::CelulaB() : Celula(TIPO_CELULA::CELULA_B){
    this->inicia();
}

CelulaB::CelulaB(double x, double y) : Celula(TIPO_CELULA::CELULA_B,x,y){

}

void CelulaB::inicia(){
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(produzAnticorpo()));
    timer->start(500);
}

void CelulaB::loop(){

    envelhece();

    if(qrand() % 400 == 1){
        CelulaB *tmp = new CelulaB();
        tmp->moveToThread(SistemaImunologico::getThread());
        SistemaImunologico::getInstancia()->renderizaCelula(tmp);
    }

    if(virus) return;

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

//        inicia();
    }

    moveRand();

}

void CelulaB::produzAnticorpo(){
    if(!SistemaImunologico::getInstancia()->getCelulas()->contains(this)) {timer->stop(); return;}
    if(!virus || SistemaImunologico::getInstancia()->pausado) return;

    Anticorpo* a = new Anticorpo(x,y,virus);
    a->moveRand();
    SistemaImunologico::getInstancia()->renderizaCelula(a);

    virus->setQtAnticorpos(virus->getQtAnticorpos() + 1);
}

Virus* CelulaB::getVirus(){
    return virus;
}
