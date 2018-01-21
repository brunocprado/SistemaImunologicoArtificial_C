#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <stdlib.h>

#include "sistemaimunologico.h"
#include "quimica/camadaquimica.h"
#include "celulas/macrofago.h"

SistemaImunologico* SistemaImunologico::INSTANCIA = 0;

SistemaImunologico::SistemaImunologico() : QThread(nullptr){
    INICIO_SISTEMA = QDateTime::currentDateTime();
    celulas = new QList<Celula*>();
    carregaParametros();
    this->start(QThread::HighPriority);
    quimica = new CamadaQuimica();
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
    for(int i =0;i<600;i++){
        celulas->append(new Macrofago());
        renderizaCelula(celulas->at(i));
    }
}

void SistemaImunologico::run(){
    msleep(2000); // PRA GARANTIR QUE TD JÁ FOI INSTANCIADO
    while(true){
        for(int i=0;i<100;i++){
            celulas->at(i)->loop();
        }
        msleep(INTERVALO_PROCESSAMENTO);
    }
}

void SistemaImunologico::renderizaCelula(Celula* celula){
    emit adicionaCelula(celula->id,celula->getTipo(),celula->getX(),celula->getY());
}

void SistemaImunologico::carregaParametros() {
    parametros = new QMap<std::string,double>();
    parametros->insert("TESTE",5);
}

double SistemaImunologico::getParametro(std::string parametro){
    return parametros->value(parametro);
}

void SistemaImunologico::log(QString texto){
    qDebug() << texto;
    emit escreveLog(texto);
}

void SistemaImunologico::log(QColor cor, QString texto){
    qDebug() << texto;
    emit escreveLog(texto); //TODO INCLUIR COR
}
