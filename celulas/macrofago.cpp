#include "macrofago.h"

#include "sistemaimunologico.h"

Macrofago::Macrofago() : Celula(MACROFAGO){

}

void Macrofago::loop(){
    emit SistemaImunologico::getInstancia()->movimentaCelula(this->id,(rand() % 5 - 2),(rand() % 5 - 2));
}

Macrofago::ESTADO Macrofago::getEstado(){
    return this->estado;
}
