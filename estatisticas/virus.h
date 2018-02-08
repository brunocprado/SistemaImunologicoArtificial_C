#ifndef VIRUS_H
#define VIRUS_H

#include <QString>

class Virus{
public:
    Virus(QString identificador);

    void add();
    void sub();

    int getEpitopo();
    short getQuantidade();

private:
    short quantidade = 0;
    QString identificador;
    unsigned int epitopo;

    //====| Estatisticas |====//
    double tempoMedio = 0;
    short qtTempo = 0;
};

#endif // VIRUS_H
