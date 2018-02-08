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

Celula::Celula(TIPO_CELULA t, int x, int y){
    id=contador; contador++;
    tipo = t;
    this->x = x; this->y = y;
}

void Celula::remove(){
    SistemaImunologico::getInstancia()->getCelulas()->removeOne(this);
    emit SistemaImunologico::getInstancia()->eliminaCelula(id);
//    if(tipo == PATOGENO) { delete this; }
//    delete this;
}

void Celula::move(Celula* c){
    double angulo = atan2(c->y - y,c->x - x);
    x += 2 * cos(angulo);
    y += 2 * sin(angulo);
    emit SistemaImunologico::getInstancia()->movimentaCelula(this->id,x,y);
}

void Celula::move(short xx, short yy){
    double angulo = atan2(yy - y,xx - x);
    x += 2 * cos(angulo);
    y += 2 * sin(angulo);
    emit SistemaImunologico::getInstancia()->movimentaCelula(this->id,x,y);
}

double Celula::calculaDistancia(short x, short y){
    int deltaX = this->x - x;
    int deltaY = this->y - y;
    return sqrt(pow(deltaX,2) + pow(deltaY,2));
}

double Celula::calculaDistancia(Celula *c){
    int deltaX = x - c->x;
    int deltaY = y - c->y;
    return sqrt(pow(deltaX,2) + pow(deltaY,2));
}

void Celula::emiteQuimica(short tipo, int qt){
    CompostoQuimico* composto = new CompostoQuimico((CompostoQuimico::TIPO_COMPOSTO) tipo,qt,this);
    SistemaImunologico::getInstancia()->getQuimica()->getCompostos()->append(composto);
    emit SistemaImunologico::getInstancia()->adicionaComposto(composto->getId(),composto->getTipo(),composto->getRaio(),composto->x,composto->y);
}

Celula::TIPO_CELULA Celula::getTipo(){
    return tipo;
}
