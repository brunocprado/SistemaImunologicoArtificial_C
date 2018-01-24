#ifndef SISTEMAIMUNOLOGICO_H
#define SISTEMAIMUNOLOGICO_H

#include <QDateTime>
#include <QThread>
#include <QString>
#include <QColor>
#include <QList>
#include <QMap>

#include "quimica/camadaquimica.h"
#include "celulas/celula.h"

#define INTERVALO_PROCESSAMENTO 30

class SistemaImunologico : public QThread{
    Q_OBJECT
public:
    explicit SistemaImunologico();

    ~SistemaImunologico();

    void inicia();

    void geraPrimeiraGeracao();
    void renderizaCelula(Celula* celula);
    void log(QString texto);
    void log(QString cor,QString texto);
    void pausar();
    void resumir();

    Q_INVOKABLE void encerra();

    static SistemaImunologico* getInstancia();

    double getParametro(std::string parametro);
    QList<Celula*>* getCelulas();
    CamadaQuimica* getQuimica();

    void setGerador(int g);

private:
    static SistemaImunologico* INSTANCIA; //SINGLETON

    unsigned int GERADOR;

    QDateTime INICIO_SISTEMA;

    QList<Celula*>* celulas;
    CamadaQuimica* quimica;
    QMap<std::string,double>* parametros;

    void carregaParametros();
    void run(); //Loop do QThread

signals:
    void adicionaCelula(int id,int tipo,int x,int y);
    void movimentaCelula(int id,int mx,int my);
    void escreveLog(QString cor,QString texto);

public slots:
};

#endif // SISTEMAIMUNOLOGICO_H
