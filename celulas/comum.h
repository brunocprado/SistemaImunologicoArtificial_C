#ifndef COMUM_H
#define COMUM_H

#include "celulas/celula.h"

class Comum : public Celula {
public:
//    enum class ESTADO {NORMAL,INFECTADA};

    explicit Comum();

    void loop();
    ESTADO getEstado();
    void setEstado(Celula::ESTADO);
    QString extra();

private:
    ESTADO estado = ESTADO::REPOUSO;

};

#endif // COMUM_H
