#ifndef PATOGENO_H
#define PATOGENO_H

#include "celulas/celula.h"
#include "estatisticas/virus.h"

class Patogeno : public Celula{
public:
    Patogeno();
    Patogeno(Virus* virus);

    void loop();

private:
    Virus* virus;

    Celula* prox = nullptr;
    bool processando = false;
};

#endif // PATOGENO_H
