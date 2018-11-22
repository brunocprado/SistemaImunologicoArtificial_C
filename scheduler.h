#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QThreadPool>
#include "celulas/celula.h"
#include "sistemaimunologico.h"

#define DELAY 20

class Runnable : public QRunnable{
    private:
        QElapsedTimer* timer = new QElapsedTimer();
    public:
        QList<Celula*>* lista = new QList<Celula*>();

        void run(){
            SistemaImunologico* s = SistemaImunologico::getInstancia();
            while(true){
                while(s->pausado) QThread::msleep(10);

                timer->start();

                for(int i =0;i<lista->length();i++){
                    lista->at(i)->loop();
                }

//                emit s->debug(timer->elapsed());
//                qDebug() << timer->elapsed();

                QThread::msleep(DELAY);
            }
        }
};

class Scheduler{
public:
    explicit Scheduler(int threads);
    ~Scheduler();

    int nThreads = 0;
    Runnable *THREADS;

    static Scheduler* getInstancia();
    void distribuiCelula(Celula* c);

private:
    static Scheduler* INSTANCIA;
    int atual = 0; //TODO ESCALONAR DE FORMA EQUILIBRADA

};

#endif // SCHEDULER_H
