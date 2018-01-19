#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>

#include "sistemaimunologico.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    SistemaImunologico sistema;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("sistema",&sistema);
//    engine.load(QUrl(QStringLiteral("qrc:/views/main.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/views/main.qml")));

//    engine.load("/views/main.qml");

    sistema.geraPrimeiraGeracao();

    return app.exec();
}
