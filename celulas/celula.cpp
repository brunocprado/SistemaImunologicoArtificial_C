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
    contador++; id=contador;
    tipo = t;
    x = rand() % 1600 + 1;
    y = rand() % 900 + 1;
}

void Celula::move(Celula* celula){
    double angulo = atan2(celula->getX() - x,celula->getY() - y);
    x += cos(angulo);
    y += sin(angulo);
}

double Celula:: calculaDistancia(int x, int y){
    double deltaX = this->x - x;
    double deltaY = this->y - y;
    return sqrt((deltaX * deltaX) + (deltaY * deltaY));
}

void Celula::emiteQuimica(int tipo, int qt){
    SistemaImunologico::getInstancia()->getQuimica()->compostos->append(new CompostoQuimico((CompostoQuimico::TIPO_COMPOSTO) tipo,qt,this));
}

Celula::TIPO_CELULA Celula::getTipo(){
    return tipo;
}

int Celula::getX(){
    return x;
}

int Celula::getY(){
    return y;
}
