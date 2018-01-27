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
    mutex = new QMutex();
    carregaParametros();
}

SistemaImunologico::~SistemaImunologico(){
    printf("Encerrando a Thread %d [Sistema imunologico (Logica)]",QThread::currentThreadId());
    free(celulas);
    this->terminate();
}

void SistemaImunologico::inicia(){
    carregaParametros();
    geraPrimeiraGeracao();
    this->start(QThread::HighPriority);
    quimica = new CamadaQuimica();
}

SistemaImunologico* SistemaImunologico::getInstancia(){
    if(INSTANCIA == 0) INSTANCIA = new SistemaImunologico();
    return INSTANCIA;
}

void SistemaImunologico::carregaParametros() {
    parametros = new QMap<std::string,double>();

    log("#f00","Carregando parametros");

    QFile arquivo("/parametros.xml");
    arquivo.open(QIODevice::ReadOnly | QIODevice::Text);

    QXmlStreamReader leitor;
    leitor.setDevice(&arquivo);
    leitor.readNext();

    while(!leitor.atEnd()) {
        if(leitor.readNext() == QXmlStreamReader::StartElement) {
            if(leitor.name() == "parametros") continue;
            log("[ " + leitor.name() + " ] = " + leitor.readElementText());
            parametros->insert(leitor.name().toString().toStdString(),leitor.readElementText().toDouble());
        }
    }

    leitor.clear();
    arquivo.close();
}

void SistemaImunologico::geraPrimeiraGeracao(){
    int nInicial = rand() % 700 + 400;
    log("#0f0",QString().fromStdString("Gerando Sistema com GERADOR = " + std::to_string(GERADOR) + " e " + std::to_string(nInicial * 10) + " leucócitos por microlitro de sangue"));
    for(int i =0;i<nInicial;i++){
        celulas->append(new Macrofago());
        renderizaCelula(celulas->at(i));
    }
}

void SistemaImunologico::run(){
    msleep(2000); // PRA GARANTIR QUE TD JÁ FOI INSTANCIADO
    while(true){
        while(pausado) msleep(5);
        for(int i=0;i<celulas->length()/8;i++){
            celulas->at(i)->loop();
        }
        msleep(INTERVALO_PROCESSAMENTO * velocidade);
    }
}

void SistemaImunologico::renderizaCelula(Celula* celula){
    emit adicionaCelula(celula->id,celula->getTipo(),celula->x,celula->y);
}

void SistemaImunologico::log(QString texto){
    qDebug() << texto;
    emit escreveLog(nullptr,texto);
}

void SistemaImunologico::log(QString cor, QString texto){
    qDebug() << texto;
    emit escreveLog(cor,texto);
}

void SistemaImunologico::pausar(){
    this->pausado = true;
}

void SistemaImunologico::resumir(){
    this->pausado = false;
}
#include <QGuiApplication>
void SistemaImunologico::encerra(){
    QGuiApplication::quit();
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

void SistemaImunologico::setGerador(int g){
    this->GERADOR = g;
    srand(GERADOR);
}
