#ifndef SISTEMAIMUNOLOGICO_H
#define SISTEMAIMUNOLOGICO_H

#include <QDateTime>
#include <QThread>
#include <QString>
#include <QList>
#include <QMap>

#include "quimica/camadaquimica.h"
#include "celulas/celula.h"
#include "estatisticas/virus.h"

class SistemaImunologico : public QThread{
    Q_OBJECT
public:
    explicit SistemaImunologico();

    ~SistemaImunologico();

    double velocidade = 1;
    bool pausado = false;

    void inicia();

    void geraPrimeiraGeracao();
    void renderizaCelula(Celula* celula);
    void eliminaCelula(Celula* celula);

    void log(QString texto);
    void log(QString cor,QString texto);

    Q_INVOKABLE void novoSistema(QString parametros);
    Q_INVOKABLE void pausar();
    Q_INVOKABLE void resumir();
    Q_INVOKABLE void mudaVelocidade(double vel);
    Q_INVOKABLE void encerra();
    Q_INVOKABLE void addPatogeno(); //DEBUG
    Q_INVOKABLE void addPatogeno(Virus* v);
    Q_INVOKABLE void mudaParametro(QString parametro,double valor);
    Q_INVOKABLE QString getParametros();

    static SistemaImunologico* getInstancia();
    static QList<CompostoQuimico*>* getCompostos();
    static QThread* getThread();

    QList<Celula*>* getCelulas();
    CamadaQuimica* getQuimica();

    QDateTime getINICIO_SISTEMA();
    double getParametro(std::string parametro);

    void setGerador(unsigned int g);

    Q_INVOKABLE QString versao_git();

    bool flag = false; //TESTE

private:
    static SistemaImunologico* INSTANCIA; //SINGLETON

    bool DEBUG = false;

    unsigned int GERADOR;

    QDateTime INICIO_SISTEMA;
    QElapsedTimer* timer;

    QList<Celula*>* celulas;
    CamadaQuimica* quimica;
    QMap<std::string,double>* parametros;
    int qtInicial;

    void carregaParametros();
    void run(); //Loop do QThread

signals:
    void adicionaCelula(Celula* celula);
    void movimentaCelula(int id);
    void eliminaCelula(int id);

    void adicionaComposto(int id,int tipo,int raio,int x,int y);
    void mudaComposto(short id,short varRaio,short concentracao);
    void eliminaComposto(int id);

    void escreveLog(QString cor,QString texto);
    void addParametro(QString parametro);
    void addVirus(Virus* virus);

    void reseta();

    //DEBUG
    void debug(int tempo);
};

#endif // SISTEMAIMUNOLOGICO_H
