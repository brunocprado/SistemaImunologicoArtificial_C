#include <QTimer>

#include "patogeno.h"
#include "quimica/compostoquimico.h"
#include "sistemaimunologico.h"

Patogeno::Patogeno() : Celula(PATOGENO){
    this->virus = new Virus("TESTE");
    this->inicia();
}

Patogeno::Patogeno(Virus *virus) : Celula(PATOGENO){
    this->virus = virus;
    this->inicia();
}

Patogeno::Patogeno(Virus *virus, double x, double y) : Celula(PATOGENO,x,y){
    this->virus = virus;
    this->inicia();
}

void Patogeno::inicia(){
    virus->add();
    emiteQuimica(CompostoQuimico::PAMP,20);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(subThread()));
    timer->start(600);
}

void Patogeno::clona(){
    Patogeno *tmp = new Patogeno(virus,x,y);
    SistemaImunologico::getInstancia()->renderizaCelula(tmp);
}

void Patogeno::subThread(){
    if(!SistemaImunologico::getInstancia()->getCelulas()->contains(this)) {timer->stop(); virus->sub(); return;}
    emiteQuimica(CompostoQuimico::PAMP,20);
}

void Patogeno::loop(){

    if(prox != nullptr){
        if(calculaDistancia(prox) < 6){
            //processando = true;
//            clona();
            prox->remove();
            prox = nullptr;
        } else {
            move(prox);
        }
        return;
    }

    double maisProx = INT16_MAX;
    double dist = 0;

   QList<Celula*>* tmp = SistemaImunologico::getInstancia()->getCelulas();
    for (int i = 0; i < tmp->length(); i++){
        Celula* celula = tmp->at(i);
        if(celula->getTipo() != LINFOCITO) continue;
        dist = calculaDistancia(celula);
        if(maisProx > dist){
            maisProx = dist;
            prox = celula;
        }
    }

    if(prox != nullptr) move(prox);
}
