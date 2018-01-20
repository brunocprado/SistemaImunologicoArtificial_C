#ifndef CAMADAQUIMICA_H
#define CAMADAQUIMICA_H

#include <QThread>

#include "sistemaimunologico.h"

class CamadaQuimica : public QThread{
public:
    CamadaQuimica();

    void run();
private:
    SistemaImunologico* sistema;

};

#endif // CAMADAQUIMICA_H
