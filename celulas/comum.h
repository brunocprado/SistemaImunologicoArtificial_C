#ifndef COMUM_H
#define COMUM_H

#include "estatisticas/virus.h"
#include "celulas/celula.h"

class Comum : public Celula {
public:
//    enum class ESTADO {NORMAL,INFECTADA};

    explicit Comum();

    void loop();
    ESTADO getEstado();
    void setEstado(Celula::ESTADO);
    void setVirus(Virus* v){virus=v;}
    Virus* getVirus(){return virus;}
    QString extra();

private:
    ESTADO estado = ESTADO::REPOUSO;
    Virus* virus = nullptr;

};

#endif // COMUM_H
