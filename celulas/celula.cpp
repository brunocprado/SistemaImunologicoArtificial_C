#include <stdlib.h>
#include "celula.h"

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

void Celula::move(int x, int y){
    this->x = x;
    this->y = y;
}

double Celula:: calculaDistancia(int x, int y){
    return 1;
}

Celula::TIPO_CELULA Celula::getTipo(){
    return tipo;
}

