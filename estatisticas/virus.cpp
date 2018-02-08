#include "virus.h"

Virus::Virus(QString identificador){
    this->epitopo = rand() % INT16_MAX;
}

void Virus::add(){
    quantidade++;
}

void Virus::sub(){
    quantidade--;
}

int Virus::getEpitopo(){
    return epitopo;
}

short Virus::getQuantidade(){
    return quantidade;
}
