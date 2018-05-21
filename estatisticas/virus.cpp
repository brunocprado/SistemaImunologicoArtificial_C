#include "sistemaimunologico.h"
#include "virus.h"

/**
 * Classe para fins de Histórico e estatisticas sobre determinada classe de Patogenos.
 * @author Bruno Prado
*/

Virus::Virus(QString identificador){
    this->identificador = identificador;
    this->epitopo = rand() % INT16_MAX;
    emit SistemaImunologico::getInstancia()->addVirus(this);
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
    return children().count();
}
