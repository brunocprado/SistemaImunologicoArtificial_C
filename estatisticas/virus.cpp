#include "sistemaimunologico.h"
#include "virus.h"

Virus::Virus(QString identificador){
    this->identificador = identificador;
    this->epitopo = rand() % INT16_MAX;
    SistemaImunologico::getInstancia()->getSimulacoes()->append(this);
    emit SistemaImunologico::getInstancia()->addVirus(this);
}

void Virus::add(){
    quantidade++;
}

void Virus::sub(){
    quantidade--;
}

void Virus::addTemporizacao(int tempo){
    tempoMedio = (tempoMedio * qtTempo) + tempo;
    qtTempo++;
}

QString Virus::getIdentificador(){
    return identificador;
}

int Virus::getEpitopo(){
    return epitopo;
}

short Virus::getQuantidade(){
    return quantidade;
}
