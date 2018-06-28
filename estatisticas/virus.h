#ifndef VIRUS_H
#define VIRUS_H

#include <QString>
#include <QtCore>

class Virus : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString identificador READ getIdentificador CONSTANT)
    Q_PROPERTY(short quantidade READ getQuantidade)
    Q_PROPERTY(short anticorpos READ getQtAnticorpos)
public:
    Virus(QString identificador);

    void addTemporizacao(int tempo);

    QString getIdentificador();
    int getEpitopo();
    short getQuantidade();
    short getQtAnticorpos();
    void setQtAnticorpos(short qt);

private:
    QString identificador;
    unsigned int epitopo;

    //====| Estatisticas |====//
    double tempoMedio = 0;
    short qtTempo = 0;
    short qtAnticorpos = 0;
};

#endif // VIRUS_H
