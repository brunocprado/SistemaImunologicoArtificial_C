#ifndef VIRUS_H
#define VIRUS_H

#include <QString>
#include <QtCore>

class Virus : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString identificador READ getIdentificador CONSTANT)
    Q_PROPERTY(short quantidade READ getQuantidade)
public:
    Virus(QString identificador);

    void add();
    void sub();

    void addTemporizacao(int tempo);

    QString getIdentificador();
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
