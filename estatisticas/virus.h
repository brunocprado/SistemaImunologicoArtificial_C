#ifndef VIRUS_H
#define VIRUS_H

#include <QString>
#include <QtCore>

class Virus : public QObject{
    Q_OBJECT
public:
    Virus(QString identificador);

    void add();
    void sub();

    void addTemporizacao(int tempo);

    int getEpitopo();
    Q_INVOKABLE short getQuantidade();

private:
    short quantidade = 0;
    QString identificador;
    unsigned int epitopo;

    //====| Estatisticas |====//
    double tempoMedio = 0;
    short qtTempo = 0;
};

#endif // VIRUS_H
