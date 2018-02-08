#ifndef VIRUS_H
#define VIRUS_H

#include <QString>

class Virus{
public:
    Virus(QString identificador);

    void add();
    void remove();

    int getEpitopo();
    short getQuantidade();

private:
    short quantidade = 0;
    QString identificador;
    unsigned int epitopo;
};

#endif // VIRUS_H
