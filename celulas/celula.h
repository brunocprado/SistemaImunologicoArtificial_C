#ifndef CELULA_H
#define CELULA_H

class Celula{
public:
    enum TIPO_CELULA {COMUM,MACROFAGO,NEUTROFILO,LINFOCITO};
    TIPO_CELULA getTipo();

    int id;

    //=======| Construtores |======//
    Celula();
    explicit Celula(TIPO_CELULA t);

    //=======| Funções |========// TODO : Get/Set
    void move(Celula* celula);
    void move(int x,int y);
    double calculaDistancia(int x,int y);
    void emiteQuimica();

    virtual void loop() = 0;

    int getX();
    int getY();

private:
    TIPO_CELULA tipo;
    int x,y;
};

#endif // CELULA_H
