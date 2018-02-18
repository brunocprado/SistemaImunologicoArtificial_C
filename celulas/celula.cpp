#include <stdlib.h>
#include <math.h>

#include "sistemaimunologico.h"
#include "celula.h"
#include "celulas/patogeno.h"
#include "quimica/compostoquimico.h"

static int contador = 0;

Celula::Celula(TIPO_CELULA t){
    id=contador; contador++;
    tipo = t;
    x = rand() % 1600 + 1;
    y = rand() % 900 + 1;
}

Celula::Celula(TIPO_CELULA t, double x, double y){
    id=contador; contador++;
    tipo = t;
    this->x = x; this->y = y;
}

void Celula::remove(){
    SistemaImunologico::getInstancia()->getCelulas()->removeOne(this);
    emit SistemaImunologico::getInstancia()->eliminaCelula(id);
    if(tipo == TIPO_CELULA::PATOGENO) {
        ((Patogeno*)this)->getVirus()->sub();
    }
}

void Celula::move(Celula* c){
    double angulo = atan2(c->y - y,c->x - x);
    x += cos(angulo);
    y += sin(angulo);
    emit SistemaImunologico::getInstancia()->movimentaCelula(id);
}

void Celula::move(short xx, short yy){
    double angulo = atan2(yy - y,xx - x);
    x += cos(angulo);
    y += sin(angulo);
    emit SistemaImunologico::getInstancia()->movimentaCelula(id);
}

double Celula::calculaDistancia(short x, short y){
    return sqrt(pow(this->x - x,2) + pow(this->y - y,2));
}

double Celula::calculaDistancia(Celula *c){
    return sqrt(pow(x - c->x,2) + pow(y - c->y,2));
}

void Celula::emiteQuimica(short tipo, int qt){
    CompostoQuimico* composto = new CompostoQuimico((CompostoQuimico::TIPO_COMPOSTO) tipo,qt,this);
    SistemaImunologico::getInstancia()->getQuimica()->getCompostos()->append(composto);
    emit SistemaImunologico::getInstancia()->adicionaComposto(composto->getId(),composto->getTipo(),composto->getRaio(),composto->x,composto->y);
}

Celula::TIPO_CELULA Celula::getTipo(){
    return tipo;
}
