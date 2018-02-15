#include "sistemaimunologico.h"
#include "neutrofilo.h"

Neutrofilo::Neutrofilo() : Celula(TIPO_CELULA::NEUTROFILO){

}

void Neutrofilo::loop(){
    emit SistemaImunologico::getInstancia()->movimentaCelula(id);
}
