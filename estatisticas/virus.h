#ifndef VIRUS_H
#define VIRUS_H

#include <QString>

class Virus{
public:
    Virus(QString identificador);

    void add();
    void remove();

    int getEpitopo();
private:
    short quantidade;
    QString identificador;
    int epitopo;
};

#endif // VIRUS_H
