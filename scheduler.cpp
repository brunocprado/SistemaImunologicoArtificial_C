#include "scheduler.h"

Scheduler::Scheduler(int threads){
    nThreads = threads;
    THREADS = new Runnable[threads];

    for(int i=0;i<threads;i++){
        QThreadPool::globalInstance()->start(&THREADS[i],QThread::HighPriority);
    }
}

void Scheduler::distribuiCelula(Celula *c){
//    for(int i=0;i<nThreads;i++){
//        if(THREADS[i]->lista->length())
//    }


      THREADS[atual].lista->append(c);

      if(++atual >= nThreads) atual = 0;

}
