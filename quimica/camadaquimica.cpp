#include "quimica/camadaquimica.h"

CamadaQuimica::CamadaQuimica() : QThread(nullptr){
    this->compostos = new QList<CompostoQuimico*>();
    this->start(QThread::NormalPriority);
}

void CamadaQuimica::run(){

}

void CamadaQuimica::remove(CompostoQuimico *composto){
    compostos->removeOne(composto);
    free(composto);
    //ESCONDE
}

QList<CompostoQuimico*>* CamadaQuimica::getCompostos(){
    return compostos;
}
