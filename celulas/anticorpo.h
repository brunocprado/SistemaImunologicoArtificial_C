#ifndef ANTICORPO_H
#define ANTICORPO_H

#include "estatisticas/virus.h"
#include "celulas/celula.h"

class Anticorpo : public Celula{
public:
    Anticorpo(double x,double y,Virus* v);

    void loop();

    Virus* getVirus();

    QString extra();

private:
    Virus* virus;
};

#endif // ANTICORPO_H
