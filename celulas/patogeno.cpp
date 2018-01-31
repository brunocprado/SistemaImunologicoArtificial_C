#include "patogeno.h"

Patogeno::Patogeno() : Celula(PATOGENO){
    this->virus = new Virus("TESTE");
}

Patogeno::Patogeno(Virus *virus) : Celula(PATOGENO){
    this->virus = virus;
}

void Patogeno::loop(){
    //TODO
}
