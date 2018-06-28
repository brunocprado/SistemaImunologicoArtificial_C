#include "sistemaimunologico.h"
#include "virus.h"

/**
 * Classe para fins de Histórico e estatisticas sobre determinada classe de Patogenos.
 * @author Bruno Prado
*/

Virus::Virus(QString identificador){
    moveToThread(SistemaImunologico::getThread());
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

short Virus::getQtAnticorpos(){
    return qtAnticorpos;
}

void Virus::setQtAnticorpos(short qt){
    qtAnticorpos = qt;
}
