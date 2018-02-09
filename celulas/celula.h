#ifndef CELULA_H
#define CELULA_H

//#include <QtCore>

class Celula {
//    Q_GADGET
//    Q_ENUMS(TIPO_CELULA)
public:
    enum TIPO_CELULA {COMUM,PATOGENO,MACROFAGO,NEUTROFILO,LINFOCITO};
    TIPO_CELULA getTipo();

    int id;

    //=======| Construtores |======//
    Celula(TIPO_CELULA t = COMUM);
    Celula(TIPO_CELULA t,double x,double y);

    //=======| Funções |========// TODO : Get/Set
    void move(Celula* celula);
    void move(short xx,short yy);
    double calculaDistancia(short int x,short int y);
    double calculaDistancia(Celula* c);
    void emiteQuimica(short tipo,int qt);
    void remove();

    virtual void loop() = 0;

    double x,y;

protected:
    TIPO_CELULA tipo;
    double velMovimento = 1.0;

};

#endif // CELULA_H
