#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <stdlib.h>

#include "sistemaimunologico.h"
#include "quimica/camadaquimica.h"
#include "celulas/macrofago.h"
#include "celulas/neutrofilo.h"
#include "celulas/patogeno.h"

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
    quimica = new CamadaQuimica();
    geraPrimeiraGeracao();
    this->start(QThread::HighPriority);
}

SistemaImunologico* SistemaImunologico::getInstancia(){
    if(INSTANCIA == 0) INSTANCIA = new SistemaImunologico();
    return INSTANCIA;
}

QList<CompostoQuimico*>* SistemaImunologico::getCompostos(){
    return INSTANCIA->getQuimica()->getCompostos();
}

void SistemaImunologico::carregaParametros() {
    parametros = new QMap<std::string,double>();

    log("#f00","Carregando parametros");

    QFile arquivo("/home/bruno/SistemaImunologicoArtificial_C/parametros.xml");
    arquivo.open(QIODevice::ReadOnly | QIODevice::Text);

    QXmlStreamReader leitor;
    leitor.setDevice(&arquivo);
    leitor.readNext();

    while(!leitor.atEnd()) {
        if(leitor.readNext() == QXmlStreamReader::StartElement) {
            if(leitor.name() == "parametros") continue;
            QString tmp = leitor.readElementText(); QString nome = leitor.name().toString();
            log("[ " + nome + " ] = " + tmp);
            parametros->insert(nome.toStdString(),tmp.toDouble());
        }
    }

    leitor.clear();
    arquivo.close();
}

void SistemaImunologico::geraPrimeiraGeracao(){
    int nInicial = rand() % 700 + 400;
    log("#0f0",QString().fromStdString("Gerando Sistema com GERADOR = " + std::to_string(GERADOR) + " e " + std::to_string(nInicial * 10) + " leucócitos por microlitro de sangue"));

    for(int i =0;i<(nInicial * parametros->value("NEUTROFILOS"));i++){
        renderizaCelula(new Neutrofilo());
    }

    for(int i =0;i<(nInicial * parametros->value("MACROFAGOS"));i++){
        renderizaCelula(new Macrofago());
    }

    for(int i =0;i<(nInicial * parametros->value("LINFOCITOS"));i++){
//        renderizaCelula(new Macrofago());
    }
}

QList<Celula*>::iterator i;
void SistemaImunologico::run(){
    msleep(2000);
    while(true){
        while(pausado) msleep(5);
        for (i = celulas->begin(); i != celulas->end(); ++i){
            (*i)->loop();
        }
        msleep(INTERVALO_PROCESSAMENTO * velocidade);
    }
}

void SistemaImunologico::renderizaCelula(Celula* celula){
    celulas->append(celula);
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

void SistemaImunologico::encerra(){


}

void SistemaImunologico::addPatogeno(){
    printf("DEBUG");
    celulas->append(new Patogeno());
    renderizaCelula(celulas->last());
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
