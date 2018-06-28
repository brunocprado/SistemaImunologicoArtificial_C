#ifndef COMUM_H
#define COMUM_H

#include "estatisticas/virus.h"
#include "celulas/celula.h"

class Comum : public Celula {
public:
    explicit Comum();

    void loop();
    void setVirus(Virus* v){virus=v;}
    Virus* getVirus(){return virus;}
    QString extra();

private:
    Virus* virus;

};

#endif // COMUM_H
