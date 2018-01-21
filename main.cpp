#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "sistemaimunologico.h"

int main(int argc, char *argv[]){
    #if defined(Q_OS_WIN)
        QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    #endif

    QGuiApplication app(argc, argv);

    SistemaImunologico* sistema = SistemaImunologico::getInstancia();

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("sistema",sistema);
    engine.load(QUrl(QStringLiteral("qrc:/views/terminal.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/views/main.qml")));

    for(int a = 1; a < QCoreApplication::arguments().length();a++){
        if(QCoreApplication::arguments().at(a) == QString("gerador")) {
            sistema->log(QCoreApplication::arguments().at(a+1));
            sistema->setGerador(QCoreApplication::arguments().at(a+1).toInt());
        }
    }

    sistema->geraPrimeiraGeracao();

    return app.exec();
}
