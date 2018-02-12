#include <QtWidgets/QApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "sistemaimunologico.h"
#include "estatisticas/virus.h"
#include "celulas/celula.h"

int main(int argc, char *argv[]){
    #if defined(Q_OS_WIN)
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    #endif

    QApplication app(argc, argv);

    SistemaImunologico* sistema = SistemaImunologico::getInstancia();

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("sistema",sistema);
    qRegisterMetaType<Celula*>("Celula*");
    qRegisterMetaType<Virus*>("Virus*");

    engine.load(QUrl(QStringLiteral("qrc:/views/terminal.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/views/main.qml")));

    QObject::connect(&engine, &QQmlApplicationEngine::quit, &app, &QApplication::quit);

    for(int a = 1; a < QCoreApplication::arguments().length();a++){
        if(QCoreApplication::arguments().at(a) == QString("gerador")) {
            sistema->setGerador(QCoreApplication::arguments().at(a+1).toInt());
        }
    }

    sistema->inicia();

    return app.exec();
}
