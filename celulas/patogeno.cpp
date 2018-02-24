#include "patogeno.h"
#include "quimica/compostoquimico.h"
#include "sistemaimunologico.h"

Patogeno::Patogeno() : Celula(TIPO_CELULA::PATOGENO){
    this->virus = new Virus("TESTE");
    this->inicia();
}

Patogeno::Patogeno(Virus *virus) : Celula(TIPO_CELULA::PATOGENO){
    this->virus = virus;
    this->inicia();
}

Patogeno::Patogeno(Virus *virus, double x, double y) : Celula(TIPO_CELULA::PATOGENO,x,y){
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
    Patogeno *tmp = new Patogeno(virus,x+5,y+5);
    tmp->moveToThread(SistemaImunologico::getThread());
    SistemaImunologico::getInstancia()->renderizaCelula(tmp);
}

void Patogeno::subThread(){
    if(SistemaImunologico::getInstancia()->pausado) return;
    if(!SistemaImunologico::getInstancia()->getCelulas()->contains(this)) {timer->stop(); virus->sub(); return;}
    emiteQuimica(CompostoQuimico::PAMP,20);
}

void Patogeno::loop(){

    if(processando && !SistemaImunologico::getInstancia()->getCelulas()->contains(alvo)){
        processando = false;
        alvo = nullptr;
    }

    if(processando) {   
        if(inicioProc.elapsed() >= 800){
            processando = false;
            alvo->remove();
            alvo = nullptr;

            clona();
        } else return;
    }

    if(alvo != nullptr){
        if(calculaDistancia(alvo) < 6){
            processando = true;
            inicioProc.start();
        } else {
            move(alvo);
        }
        return;
    }

    double maisprox = INT16_MAX;
    double dist = 0;

   QList<Celula*>* tmp = SistemaImunologico::getInstancia()->getCelulas();
    for (int i = 0; i < tmp->length(); i++){
        Celula* celula = tmp->at(i);
        if(celula->getTipo() != TIPO_CELULA::LINFOCITO) continue;
        dist = calculaDistancia(celula);
        if(maisprox > dist){
            maisprox = dist;
            alvo = celula;
        }
    }

    if(alvo != nullptr) move(alvo);
}

QString Patogeno::extra(){
    QJsonObject json;
    json.insert("virus",QVariant::fromValue(virus->getIdentificador()).value<QString>());
    if(alvo != nullptr) json.insert("alvo",alvo->id);

    QJsonDocument tmp(json);
    return tmp.toJson();
}

Virus* Patogeno::getVirus(){
    return virus;
}
