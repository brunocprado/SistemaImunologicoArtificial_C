#ifndef CAMADAQUIMICA_H
#define CAMADAQUIMICA_H

#include <QThread>

class CamadaQuimica : public QThread{
public:
    CamadaQuimica();

    void run();
private:

};

#endif // CAMADAQUIMICA_H
