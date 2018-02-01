#include "quimica/camadaquimica.h"
#include "sistemaimunologico.h"

SistemaImunologico* sistema = SistemaImunologico::getInstancia();

CamadaQuimica::CamadaQuimica() : QThread(nullptr){
    this->compostos = new QList<CompostoQuimico*>();
    this->start(QThread::NormalPriority);
}

void CamadaQuimica::run(){
    msleep(2100);
    while(true){
        while(sistema->pausado) msleep(5);
        QList<CompostoQuimico*>::iterator i = compostos->begin();
        for (; i != compostos->end(); ++i){
            (*i)->aumentaRaio(4);
        }
        msleep(200 * sistema->velocidade);
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
