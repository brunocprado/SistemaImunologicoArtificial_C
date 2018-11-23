#include <stdlib.h>
#include <math.h>

#include "sistemaimunologico.h"
#include "scheduler.h"
#include "celula.h"
#include "celulas/patogeno.h"
#include "celulas/anticorpo.h"
#include "quimica/compostoquimico.h"

static int contador = 0;

Celula::Celula(TIPO_CELULA t){
    id=contador; contador++;
    tipo = t;
    x = qrand() % 1600 + 1;
    y = qrand() % 900 + 1; //TODO moveToThread(Sistema)???? <-- AVALIAR
}

Celula::Celula(TIPO_CELULA t, double x, double y){
    id=contador; contador++;
    tipo = t;
    this->x = x; this->y = y;
}

void Celula::envelhece(){
    tempoVida++;
    switch(tipo){
        case TIPO_CELULA::PATOGENO:  if(tempoVida >= SistemaImunologico::getInstancia()->getParametro("VIDA_ANTIGENO")) remove(); break;
        case TIPO_CELULA::MACROFAGO: if(tempoVida >= SistemaImunologico::getInstancia()->getParametro("VIDA_MACROFAGO")) remove(); break;
        case TIPO_CELULA::CELULA_B:  if(tempoVida >= SistemaImunologico::getInstancia()->getParametro("VIDA_CELULA_B")) remove(); break;
        case TIPO_CELULA::ANTICORPO: if(tempoVida >= SistemaImunologico::getInstancia()->getParametro("VIDA_ANTICORPO")) remove(); break;
        default: break;
    }
}

void Celula::remove(){
    SistemaImunologico::getInstancia()->getCelulas()->removeOne(this);
    Scheduler::getInstancia()->THREADS[tid].lista->removeOne(this);
    emit SistemaImunologico::getInstancia()->eliminaCelula(id);
    if(tipo == TIPO_CELULA::PATOGENO){
        static_cast<Patogeno*>(this)->setParent(nullptr);
//         static_cast<Patogeno*>(this)->
    }
    if(tipo == TIPO_CELULA::ANTICORPO){
        Virus* v = static_cast<Anticorpo*>(this)->getVirus();
        v ->setQtAnticorpos(v->getQtAnticorpos() - 1);
    }
    //TODO GARBAGE COLECTOR
//    SistemaImunologico::getInstancia()->gc->append(this);

}

void Celula::move(Celula* c){
    double angulo = atan2(c->y - y,c->x - x);
    x += cos(angulo) * velMovimento;
    y += sin(angulo) * velMovimento;
    emit SistemaImunologico::getInstancia()->movimentaCelula(id);
}

void Celula::move(short xx, short yy){
    double angulo = atan2(yy - y,xx - x);
    x += cos(angulo) * velMovimento;
    y += sin(angulo) * velMovimento;
    emit SistemaImunologico::getInstancia()->movimentaCelula(id);
}

void Celula::moveRand(){
    x += (qrand() % 3 - 1) * velMovimento;
    y += (qrand() % 3 - 1) * velMovimento;
    emit SistemaImunologico::getInstancia()->movimentaCelula(id);
}

void Celula::moveRand(double v){
    x += (qrand() % 3 - 1) * v;
    y += (qrand() % 3 - 1) * v;
    emit SistemaImunologico::getInstancia()->movimentaCelula(id);
}

double Celula::calculaDistancia(int x, int y){
    return sqrt(pow(this->x - x,2) + pow(this->y - y,2));
}

double Celula::calculaDistancia(Celula *c){
    return sqrt(pow(x - c->x,2) + pow(y - c->y,2));
}

void Celula::emiteQuimica(short tipo, int qt){
    CompostoQuimico* composto = new CompostoQuimico(static_cast<CompostoQuimico::TIPO_COMPOSTO>(tipo),qt,this);
    SistemaImunologico::getInstancia()->getQuimica()->getCompostos()->append(composto);
    emit SistemaImunologico::getInstancia()->adicionaComposto(composto->getId(),composto->getTipo(),composto->getRaio(),composto->x,composto->y);
}

Celula::TIPO_CELULA Celula::getTipo(){ return tipo; }
Celula::ESTADO Celula::getEstado(){ return estado; }

void Celula::setEstado(Celula::ESTADO e){
    estado = e;
}
