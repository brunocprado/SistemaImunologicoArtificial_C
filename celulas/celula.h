#ifndef CELULA_H
#define CELULA_H

class Celula{
public:
    enum TIPO_CELULA {COMUM,PATOGENO,MACROFAGO,NEUTROFILO,LINFOCITO};
    TIPO_CELULA getTipo();

    int id;

    //=======| Construtores |======//
    Celula();
    explicit Celula(TIPO_CELULA t);

    //=======| Funções |========// TODO : Get/Set
    void move(Celula* celula);
    void move(short int x,short int y);
    double calculaDistancia(short int x,short int y);
    void emiteQuimica(int tipo,int qt);

    virtual void loop() = 0;

    unsigned short int x,y;

private:
    TIPO_CELULA tipo;

};

#endif // CELULA_H
