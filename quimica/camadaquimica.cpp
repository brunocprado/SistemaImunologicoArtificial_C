#include "quimica/camadaquimica.h"
#include "sistemaimunologico.h"

SistemaImunologico* sistema = SistemaImunologico::getInstancia();

CamadaQuimica::CamadaQuimica() : QThread(nullptr){
    this->compostos = new QList<CompostoQuimico*>();
    this->start(QThread::NormalPriority);
}

void CamadaQuimica::run(){
    while(true){
        while(sistema->pausado) msleep(5);
        msleep(200 * sistema->velocidade);
    }
}

void CamadaQuimica::remove(CompostoQuimico *composto){
    compostos->removeOne(composto);
    free(composto);
    //ESCONDE
}

QList<CompostoQuimico*>* CamadaQuimica::getCompostos(){
    return compostos;
}
