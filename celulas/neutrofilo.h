#ifndef NEUTROFILO_H
#define NEUTROFILO_H

#include "celulas/celula.h"

class Neutrofilo : public virtual Celula{
public:
    Neutrofilo();

    void loop();

};

#endif // NEUTROFILO_H
