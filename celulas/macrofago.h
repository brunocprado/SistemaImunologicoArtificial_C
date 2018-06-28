#ifndef MACROFAGO_H
#define MACROFAGO_H

#include <QDateTime>

#include "celula.h"

class Macrofago : public virtual Celula {
public:
    explicit Macrofago();

    void loop();

    QString extra();

private:
    Celula* alvo = nullptr;
    QDateTime tempoDetectado;

};

#endif // MACROFAGO_H
