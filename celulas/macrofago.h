#ifndef MACROFAGO_H
#define MACROFAGO_H

#include "celula.h"

class Macrofago : public virtual Celula{
public:
    explicit Macrofago();

    void loop();
};

#endif // MACROFAGO_H
