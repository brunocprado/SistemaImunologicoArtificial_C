#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <stdlib.h>

#include "sistemaimunologico.h"
#include "quimica/camadaquimica.h"
#include "celulas/macrofago.h"

SistemaImunologico* SistemaImunologico::INSTANCIA = 0;

SistemaImunologico::SistemaImunologico() : QThread(nullptr){
    GERADOR = time(0); srand(GERADOR);
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

void SistemaImunologico::carregaParametros() {
    parametros = new QMap<std::string,double>();
    parametros->insert("TESTE",5);
}

void SistemaImunologico::geraPrimeiraGeracao(){
    int nInicial = rand() % 700 + 400;
    log(QString().fromStdString(std::to_string(nInicial)));
    for(int i =0;i<600;i++){
        celulas->append(new Macrofago());
        renderizaCelula(celulas->at(i));
    }
}

void SistemaImunologico::run(){
    msleep(2000); // PRA GARANTIR QUE TD JÁ FOI INSTANCIADO
    while(true){
        for(int i=0;i<50;i++){
            celulas->at(i)->loop();
        }
        msleep(INTERVALO_PROCESSAMENTO / 10);
    }
}

void SistemaImunologico::renderizaCelula(Celula* celula){
    emit adicionaCelula(celula->id,celula->getTipo(),celula->x,celula->y);
}

void SistemaImunologico::log(QString texto){
    qDebug() << texto;
    emit escreveLog(texto);
}

void SistemaImunologico::log(QColor cor, QString texto){
    qDebug() << texto;
    emit escreveLog(texto); //TODO INCLUIR COR
}

double SistemaImunologico::getParametro(std::string parametro){
    return parametros->value(parametro);
}

CamadaQuimica* SistemaImunologico::getQuimica(){
    return quimica;
}

QList<Celula*>* SistemaImunologico::getCelulas(){
    return celulas;
}
