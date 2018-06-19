#ifndef CELULAB_H
#define CELULAB_H

#include <QtCore>

#include "celulas/celula.h"
#include "celulas/patogeno.h"
#include "estatisticas/virus.h"

class CelulaB : public Celula {
    Q_OBJECT
public:
    explicit CelulaB();
    CelulaB(double x,double y);

    void loop();

    Virus* getVirus();
//    ESTADO getEstado();
    QString extra(){return "";}

private:
    Patogeno* alvo = nullptr;
    Virus* virus = nullptr;
    ESTADO estado = ESTADO::REPOUSO;
    QTimer* timer;

    void inicia();

public slots:
    void produzAnticorpo();

};

#endif // CELULAB_H
