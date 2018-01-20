#include "macrofago.h"

#include "sistemaimunologico.h"

Macrofago::Macrofago() : Celula(MACROFAGO){

}

void Macrofago::loop(){
    emit SistemaImunologico::getInstancia()->movimentaCelula(this->id,(rand() % 5 - 2),(rand() % 5 - 2));
//    emit SistemaImunologico::getInstancia()->moveCelula(this->id,2,2);
//    SistemaImunologico::getInstancia()->movimentaCelula(this);
//    printf("T");
}
