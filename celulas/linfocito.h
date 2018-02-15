#ifndef LINFOCITO_H
#define LINFOCITO_H

#include "celulas/celula.h"

class Linfocito : public virtual Celula {
public:
    Linfocito();

    void loop();
    QString extra(){return "";}
};

#endif // LINFOCITO_H
