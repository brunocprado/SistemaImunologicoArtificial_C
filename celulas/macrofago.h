#ifndef MACROFAGO_H
#define MACROFAGO_H

#include <QDateTime>

#include "celula.h"

class Macrofago : public virtual Celula {
public:
    explicit Macrofago();

    void loop();

    QString extra(){
        QJsonObject json;
        json.insert("estado",QVariant::fromValue(estado).value<QString>());
        if(alvo != nullptr) json.insert("alvo",alvo->id);

        QJsonDocument tmp(json);
        return tmp.toJson();
    }

    ESTADO getEstado();

private:
    ESTADO estado;

    //====| RUNTIME |====//
    Celula* alvo = nullptr;
    QDateTime tempoDetectado;
};

#endif // MACROFAGO_H
