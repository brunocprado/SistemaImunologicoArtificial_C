#ifndef CELULA_H
#define CELULA_H

#include <QObject>

class Celula{
public:
    enum TIPO_CELULA {COMUM,MACROFAGO,NEUTROFILO,LINFOCITO};
    TIPO_CELULA getTipo();

    Celula();
    explicit Celula(TIPO_CELULA t);

    int x,y,id;
private:
    TIPO_CELULA tipo;

};

#endif // CELULA_H
