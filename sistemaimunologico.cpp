#include <QThread>
#include <QtConcurrent/QtConcurrent>
#include <stdlib.h>

#include "sistemaimunologico.h"
#include "quimica/camadaquimica.h"
#include "celulas/macrofago.h"
#include "celulas/neutrofilo.h"
#include "celulas/linfocito.h"
#include "celulas/patogeno.h"

SistemaImunologico* SistemaImunologico::INSTANCIA = 0;

SistemaImunologico::SistemaImunologico() : QThread(){
    GERADOR = time(0); srand(GERADOR);
    INICIO_SISTEMA = QDateTime::currentDateTime();
    celulas = new QList<Celula*>();
}

SistemaImunologico::~SistemaImunologico(){
    printf("Encerrando a Thread %d [Sistema imunologico (Logica)]\n",QThread::currentThreadId());
    free(celulas);
    delete quimica;
    this->terminate();
}

void SistemaImunologico::inicia(){
    log("Sistema iniciado em : " + INICIO_SISTEMA.toString());
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

    QFile arquivo("/parametros.xml");
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
            emit addParametro(nome);
        }
    }

    leitor.clear();
    arquivo.close();
}

void SistemaImunologico::geraPrimeiraGeracao(){
    int nInicial = rand() % (int)(parametros->value("TAM_MEDIO_SUPERIOR") - parametros->value("TAM_MEDIO_INFERIOR")) + parametros->value("TAM_MEDIO_INFERIOR");
    log("#0f0",QString().fromStdString("Gerando Sistema com GERADOR = " + std::to_string(GERADOR) + " e " + std::to_string(nInicial * 10) + " leucócitos por microlitro de sangue"));

    for(int i =0;i<(nInicial * parametros->value("NEUTROFILOS"));i++){
//        renderizaCelula(new Neutrofilo());
    }

    for(int i =0;i<(nInicial * parametros->value("MACROFAGOS") * 5);i++){
        renderizaCelula(new Macrofago());
    }

    for(int i =0;i<(nInicial * parametros->value("LINFOCITOS"));i++){
//        renderizaCelula(new Linfocito());
    }
}

void SistemaImunologico::run(){
    while(true){
        while(pausado) msleep(5);
        for (int i = 0;i < celulas->length(); i++){
            celulas->at(i)->loop();
        }
        msleep(30 * velocidade);
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
    delete this;
}

void SistemaImunologico::addPatogeno(){
    for(int i = 0;i<2;i++){
        celulas->append(new Patogeno());
        renderizaCelula(celulas->last());
    }
}

void SistemaImunologico::setGerador(int g){
    this->GERADOR = g;
    srand(GERADOR);
}

double SistemaImunologico::getParametro(std::string parametro){
    return parametros->value(parametro);
}

void SistemaImunologico::mudaParametro(QString parametro, double valor){
    parametros->insert(parametro.toStdString(),valor);
    log("[ " + parametro + " ] ALTERADO PARA : " + QString::number(valor));
}

CamadaQuimica* SistemaImunologico::getQuimica(){
    return quimica;
}

QList<Celula*>* SistemaImunologico::getCelulas(){
    return celulas;
}
