#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>

#include <QQuickItem>

#include "celula.h"

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
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    sistema.geraPrimeiraGeracao();

    return app.exec();
}
