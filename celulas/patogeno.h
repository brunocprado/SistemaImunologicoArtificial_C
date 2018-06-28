#ifndef PATOGENO_H
#define PATOGENO_H

#include <QObject>
#include <QDateTime>
#include <QTimer>
#include <QElapsedTimer>

#include "celulas/celula.h"
#include "estatisticas/virus.h"

class Patogeno : public Celula{
    Q_OBJECT
public:
    Patogeno();
    Patogeno(Virus* virus);
    Patogeno(Virus *virus,double x,double y);

    void loop();
    QString extra();

    Virus* getVirus();
    QDateTime getInicio();
    QTimer* timer;
    bool suprimido = false;

private:
    void inicia();
    void clona();

    Virus* virus;

    QDateTime inicio;
    Celula* alvo = nullptr;
    bool processando = false;
    QElapsedTimer inicioProc;

public slots:
    void subThread();

};

#endif // PATOGENO_H
