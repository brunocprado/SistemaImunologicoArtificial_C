#include "scheduler.h"

/*
 * Teste de escalonamento do processamento
 * @author Bruno Prado
*/

Scheduler* Scheduler::INSTANCIA = nullptr;

Scheduler::Scheduler(int threads){
    nThreads = threads;
    THREADS = new Runnable[threads];

    for(int i=0;i<threads;i++){
        QThreadPool::globalInstance()->start(&THREADS[i]);
    }
}

Scheduler::~Scheduler(){
    for(int i=0;i<nThreads;i++){
        QThreadPool::globalInstance()->tryTake(&THREADS[i]);
    }
}

Scheduler* Scheduler::getInstancia(){
    if(!INSTANCIA) INSTANCIA = new Scheduler(std::thread::hardware_concurrency());
    return INSTANCIA;
}

void Scheduler::distribuiCelula(Celula *c){
    THREADS[atual].lista->append(c);
    c->tid = atual;
    if(++atual >= nThreads) atual = 0;
}
