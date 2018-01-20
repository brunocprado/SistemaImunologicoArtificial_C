#ifndef MACROFAGO_H
#define MACROFAGO_H

#include "celula.h"

class Macrofago : public virtual Celula{
public:
    enum ESTADO {REPOUSO,ATIVO,FAGOCITANDO};
    explicit Macrofago();

    void loop();

    ESTADO getEstado();

private:
    ESTADO estado;
};

#endif // MACROFAGO_H
