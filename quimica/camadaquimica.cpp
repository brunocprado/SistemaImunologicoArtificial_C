#include "quimica/camadaquimica.h"

CamadaQuimica::CamadaQuimica() : QThread(nullptr){
//    this->compostos = new QList<CompostoQuimico*>();
    this->start(QThread::NormalPriority);
}

void CamadaQuimica::run(){

}

QList<CompostoQuimico*>* CamadaQuimica::getCompostos(){
    return compostos;
}
