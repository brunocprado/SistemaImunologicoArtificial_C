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
//        QList<CompostoQuimico*>::iterator i = compostos->begin();
        for (int i = 0; i < compostos->length(); i++){
//            if(i == compostos->end()) break;
//            (*i)->aumentaRaio(4);
                compostos->at(i)->aumentaRaio(10);
        }
        msleep(400 * sistema->velocidade);
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
