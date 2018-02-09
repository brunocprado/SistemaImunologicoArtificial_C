#ifndef PATOGENO_H
#define PATOGENO_H

#include <QObject>
#include <QTimer>

#include "celulas/celula.h"
#include "estatisticas/virus.h"

class Patogeno : public QObject , public Celula{
    Q_OBJECT
public:
    Patogeno();
    Patogeno(Virus* virus);
    Patogeno(Virus *virus,double x,double y);

    void loop();

    void clona();

private:
    QTimer* timer;

    void inicia();

    Virus* virus;

    Celula* prox = nullptr;
    bool processando = false;

public slots:
    void subThread();

};

#endif // PATOGENO_H
