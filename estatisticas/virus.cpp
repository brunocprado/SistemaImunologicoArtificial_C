#include "sistemaimunologico.h"
#include "virus.h"

Virus::Virus(QString identificador){
    this->epitopo = rand() % INT16_MAX;
    SistemaImunologico::getInstancia()->getSimulacoes()->append(this);
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

int Virus::getEpitopo(){
    return epitopo;
}

short Virus::getQuantidade(){
    return quantidade;
}
