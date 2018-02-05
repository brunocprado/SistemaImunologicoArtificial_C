#include "sistemaimunologico.h"
#include "neutrofilo.h"

Neutrofilo::Neutrofilo() : Celula(NEUTROFILO){

}

void Neutrofilo::loop(){
    emit SistemaImunologico::getInstancia()->movimentaCelula(this->id,x + rand() % 4 - 2,y + rand() % 4 - 2);
}
