#ifndef LINFOCITO_H
#define LINFOCITO_H

#include "celulas/celula.h"

class Linfocito : public virtual Celula {
public:
    Linfocito();

    void loop();
};

#endif // LINFOCITO_H
