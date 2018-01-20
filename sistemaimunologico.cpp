#include <QThread>
#include <QtConcurrent/QtConcurrent>

#include <stdlib.h>
#include "sistemaimunologico.h"
#include "celulas/macrofago.h"

SistemaImunologico* SistemaImunologico::INSTANCIA = 0;

SistemaImunologico::SistemaImunologico() : QThread(nullptr){
    INICIO_SISTEMA = QDateTime::currentDateTime();
    this->start(QThread::HighPriority);
}

SistemaImunologico::~SistemaImunologico(){
    printf("Encerrando a Thread %d [Sistema imunologico (Logica)]",QThread::currentThreadId());
    this->terminate();
}

SistemaImunologico* SistemaImunologico::getInstancia(){
    if(INSTANCIA == 0) INSTANCIA = new SistemaImunologico();
    return INSTANCIA;
}

void SistemaImunologico::geraPrimeiraGeracao(){
    for(int i =0;i<700;i++){
        celulas[i] = new Macrofago();
        renderizaCelula(celulas[i]);
    }
//    for(int i =300;i<600;i++){
//        celulas[i] = new Celula(Celula::TIPO_CELULA::NEUTROFILO);
//        renderizaCelula(celulas[i]);
//    }
}

void SistemaImunologico::run(){
    msleep(2000); // PRA GARANTIR QUE TD JÁ FOI INSTANCIADO
    while(true){
        for(int i=0;i<100;i++){
            celulas[i]->loop();
        }
        msleep(INTERVALO_PROCESSAMENTO);
    }
}

void SistemaImunologico::renderizaCelula(Celula* celula){
    emit adicionaCelula(celula->id,celula->getTipo(),celula->x,celula->y);
}

void SistemaImunologico::carregaParametros() {

}
