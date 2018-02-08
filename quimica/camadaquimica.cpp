#include "quimica/camadaquimica.h"
#include "sistemaimunologico.h"

SistemaImunologico* sistema = SistemaImunologico::getInstancia();

CamadaQuimica::CamadaQuimica() : QThread(){
    this->compostos = new QList<CompostoQuimico*>();
    this->start(QThread::NormalPriority);
}

CamadaQuimica::~CamadaQuimica(){
    printf("Encerrando a Thread %d [Quimica (Logica)]\n",thread());
    free(compostos);
    this->terminate();
}

void CamadaQuimica::run(){
    while(true){
        while(sistema->pausado) msleep(5);
        for (int i = 0; i < compostos->length(); i++){
            compostos->at(i)->aumentaRaio(5);
        }
        msleep(sistema->getParametro("TEMPO_PROPAGACAO_QUIMICOS") * sistema->velocidade);
    }
}

void CamadaQuimica::remove(CompostoQuimico *composto){
    compostos->removeOne(composto);
    emit sistema->eliminaComposto(composto->getId());
    free(composto);
}

QList<CompostoQuimico*>* CamadaQuimica::getCompostos(){
    return compostos;
}
