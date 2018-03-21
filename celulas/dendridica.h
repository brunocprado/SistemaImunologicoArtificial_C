#ifndef DENDRIDICA_H
#define DENDRIDICA_H

#include "celulas/celula.h"

class Dendridica : public virtual Celula {
public:
    Dendridica();

    void loop();
    QString extra(){return "";}
};

#endif // DENDRIDICA_H
