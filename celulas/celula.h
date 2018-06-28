#ifndef CELULA_H
#define CELULA_H

#include <QtCore>

class Celula : public QObject {
    Q_OBJECT
    Q_PROPERTY(int id READ getId CONSTANT)
    Q_PROPERTY(double x READ getX NOTIFY posicaoMudou)
    Q_PROPERTY(double y READ getY NOTIFY posicaoMudou)
    Q_PROPERTY(TIPO_CELULA tipo READ getTipo CONSTANT)
    Q_PROPERTY(QString extra READ extra)
public:
    enum class TIPO_CELULA {COMUM,PATOGENO,MACROFAGO,NEUTROFILO,LINFOCITO,CELULA_B,ANTICORPO,DENDRIDICA};
    Q_ENUM(TIPO_CELULA)

    enum class ESTADO {REPOUSO,ATIVO,FAGOCITANDO,INFECTADA,SUPRIMIDA};
    Q_ENUM(ESTADO)

    //=======| Construtores |======//
    Celula(TIPO_CELULA t = TIPO_CELULA::COMUM);
    Celula(TIPO_CELULA t,double x,double y);

    //=======| Funções |========//
    void envelhece();
    void move(Celula* celula);
    void move(short xx,short yy);
    void moveRand();
    void moveRand(double v);
    double calculaDistancia(int x,int y);
    double calculaDistancia(Celula* c);
    void emiteQuimica(short tipo,int qt);
    void remove();

    virtual void loop() = 0;
    virtual QString extra() = 0;

    int id;
    double x,y;

    int getId(){ return id; }
    double getX(){ return x; }
    double getY(){ return y; }
    TIPO_CELULA getTipo();
    ESTADO getEstado();
    double getVelMovimento();

    void setEstado(Celula::ESTADO e);

protected:
    TIPO_CELULA tipo;
    ESTADO estado = ESTADO::REPOUSO;
    short tempoVida = 0;
    double velMovimento = 1.0; //TODO INCLUIR * velMovimento no Celula::move()

signals:
    void posicaoMudou();

};

#endif // CELULA_H
