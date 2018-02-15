#ifndef NEUTROFILO_H
#define NEUTROFILO_H

#include "celulas/celula.h"

class Neutrofilo : public virtual Celula{
public:
    Neutrofilo();

    void loop();
    QString extra(){return "";}

};

#endif // NEUTROFILO_H
