#ifndef SISTEMAIMUNOLOGICO_H
#define SISTEMAIMUNOLOGICO_H

#include <QObject>
#include <QThread>
#include "celulas/celula.h"

#define TAM_MAX_CELULAS 3000

class SistemaImunologico : public QThread{
    Q_OBJECT
public:
    explicit SistemaImunologico();

    ~SistemaImunologico();

    void geraPrimeiraGeracao();

    void renderizaCelula(Celula* celula);
    void moveCelula(Celula* celula);

    static SistemaImunologico* getInstancia();

private:
    static SistemaImunologico* INSTANCIA; //SINGLETON

    Celula* celulas[TAM_MAX_CELULAS];

    void carregaParametros();
    void run(); //Loop do QThread

signals:
    void adicionaCelula(int id,int tipo,int x,int y);
    void movimentaCelula(int id,int mx,int my);

public slots:
};

#endif // SISTEMAIMUNOLOGICO_H
