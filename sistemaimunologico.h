#ifndef SISTEMAIMUNOLOGICO_H
#define SISTEMAIMUNOLOGICO_H

#include <QDateTime>
#include <QThread>
#include <QColor>
#include <QList>

#include "quimica/camadaquimica.h"
#include "celulas/celula.h"

#define INTERVALO_PROCESSAMENTO 30
#define TAM_MAX_CELULAS 1000

class SistemaImunologico : public QThread{
    Q_OBJECT
public:
    explicit SistemaImunologico();

    ~SistemaImunologico();

    void geraPrimeiraGeracao();
    void renderizaCelula(Celula* celula);
    void log(QString texto);
    void log(QColor cor,QString texto);

    static SistemaImunologico* getInstancia();
    CamadaQuimica* quimica;
private:
    static SistemaImunologico* INSTANCIA; //SINGLETON

    QDateTime INICIO_SISTEMA;

    QList<Celula*>* celulas;

    void carregaParametros();
    void run(); //Loop do QThread

signals:
    void adicionaCelula(int id,int tipo,int x,int y);
    void movimentaCelula(int id,int mx,int my);
    void escreveLog(QString texto);

public slots:
};

#endif // SISTEMAIMUNOLOGICO_H
