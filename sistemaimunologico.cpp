#include "sistemaimunologico.h"

#include "celula.h"

#include <QList>

SistemaImunologico::SistemaImunologico() : QObject(nullptr){
//    carregaParametros();
//    this->celulas = (Celula *) malloc(sizeof(Celula) * TAM_MAX_CELULAS);
//    this->celulas = new Celula[600]();
//    free(this);
}

void SistemaImunologico::geraPrimeiraGeracao(){
    for(int i =0;i<300;i++){
        celulas[i] = new Celula(Celula::TIPO_CELULA::MACROFAGO);
        renderizaCelula(celulas[i]);
    }
    for(int i =300;i<600;i++){
        celulas[i] = new Celula(Celula::TIPO_CELULA::NEUTROFILO);
        renderizaCelula(celulas[i]);
    }

//    while(true){
    for(int d = 0;d<800;d++){
        celulas[10]->x++;

        emit movimentaCelula(celulas[10]->id,celulas[10]->x,celulas[10]->y);
    }
}

Celula SistemaImunologico::getCelulas(){
    return Celula();
}

void SistemaImunologico::renderizaCelula(Celula* celula){
    emit adicionaCelula(celula->id,celula->getTipo(),celula->x,celula->y);
}

//Celula* SistemaImunologico::renderiza(){
////    QList<Celula*> tmp;

////    for(int i = 0;i<10;i++){
////        tmp.append(celulas[i]);
////    }
////    return tmp;

//    return celulas[0];
//}

//void SistemaImunologico::carregaParametros() {

//}
