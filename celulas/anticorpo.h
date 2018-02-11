#ifndef ANTICORPO_H
#define ANTICORPO_H

#include "celulas/celula.h"

class Anticorpo : public Celula{
public:
    Anticorpo(double x,double y);

    void loop();
};

#endif // ANTICORPO_H
