#ifndef SISTEMAIMUNOLOGICO_H
#define SISTEMAIMUNOLOGICO_H

#include <QObject>
#include "celulas/celula.h"

#define TAM_MAX_CELULAS 600

class SistemaImunologico : public QObject{
    Q_OBJECT
public:
    explicit SistemaImunologico();

    void geraPrimeiraGeracao();

    void renderizaCelula(Celula* celula);

    void loop();

//    Celula getCelulas();

private:
    Celula* celulas[TAM_MAX_CELULAS];

signals:
    void adicionaCelula(int id,int tipo,int x,int y);
    void movimentaCelula(int id,int mx,int my);

public slots:
};

#endif // SISTEMAIMUNOLOGICO_H
