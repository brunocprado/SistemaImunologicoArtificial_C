#include <stdlib.h>
#include <math.h>

#include "sistemaimunologico.h"
#include "celula.h"
#include "quimica/compostoquimico.h"

static int contador = 0;

Celula::Celula(){
    contador++; id=contador;
    tipo = COMUM;
    x = rand() % 1600 + 1;
    y = rand() % 900 + 1;
}

Celula::Celula(TIPO_CELULA t) {
    id=contador; contador++;
    tipo = t;
    x = rand() % 1600 + 1;
    y = rand() % 900 + 1;
}

void Celula::move(short x, short y){
//    double angulo = atan2(x - this->x,celula->y - y);
//    printf("%f",atan2((double)(celula->x - x),(double)(celula->y - y)));
//    x += 2 * cos(angulo);
//    y += 2 * sin(angulo);
//    emit SistemaImunologico::getInstancia()->movimentaCelula(this->id,x,y);
}

void Celula::move(Celula* c){
    double angulo = atan2(c->y - y,c->x - x);
    x += 2 * cos(angulo);
    y += 2 * sin(angulo);




    emit SistemaImunologico::getInstancia()->movimentaCelula(this->id,x,y);
}

double Celula:: calculaDistancia(short x, short y){
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
