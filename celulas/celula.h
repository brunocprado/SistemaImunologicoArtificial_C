#ifndef CELULA_H
#define CELULA_H

class Celula{
public:
    enum TIPO_CELULA {COMUM,MACROFAGO,NEUTROFILO,LINFOCITO};
    TIPO_CELULA getTipo();

    //=======| Construtores |======//
    Celula();
    explicit Celula(TIPO_CELULA t);

    //=======| Funções |========// TODO : Get/Set
    void move(int x,int y);
    double calculaDistancia(int x,int y);
    virtual void loop() = 0;

    int x,y,id;
private:
    TIPO_CELULA tipo;

};

#endif // CELULA_H
