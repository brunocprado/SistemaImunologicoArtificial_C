#include "quimica/camadaquimica.h"

#include <QThread>

CamadaQuimica::CamadaQuimica() : QThread(nullptr){
    this->start(QThread::NormalPriority);
}

void CamadaQuimica::run(){

}
