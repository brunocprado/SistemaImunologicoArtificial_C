#ifndef MACROFAGO_H
#define MACROFAGO_H

#include <QDateTime>

#include "celula.h"

class Macrofago : public virtual Celula {
public:
    explicit Macrofago();

    void loop();

    QString extra();

    ESTADO getEstado();

private:
    ESTADO estado;

    //====| RUNTIME |====//
    Celula* alvo = nullptr;
    QDateTime tempoDetectado;
};

#endif // MACROFAGO_H
