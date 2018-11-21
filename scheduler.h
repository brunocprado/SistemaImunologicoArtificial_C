#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QThreadPool>
#include "celulas/celula.h"

class Runnable : public QRunnable{
    public:
        QList<Celula*>* lista = new QList<Celula*>();

        void run(){
            while(true){

                for(int i =0;i<lista->length();i++){
                    lista->at(i)->loop();
                }

                QThread::msleep(10);
            }
        }
};

class Scheduler{
public:
    Scheduler(int threads);

    void distribuiCelula(Celula* c);

    int nThreads = 0;

    int atual = 0; //TODO ESCALONAR DE FORMA EQUILIBRADA

    Runnable *THREADS;

private:


};

#endif // SCHEDULER_H
