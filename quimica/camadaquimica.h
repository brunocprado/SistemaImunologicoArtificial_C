#ifndef CAMADAQUIMICA_H
#define CAMADAQUIMICA_H

#include <QThread>
#include <QList>

#include "quimica/compostoquimico.h"

class CamadaQuimica : public QThread{
public:
    CamadaQuimica();

    void run();

    QList<CompostoQuimico*>* compostos;
private:

};

#endif // CAMADAQUIMICA_H
