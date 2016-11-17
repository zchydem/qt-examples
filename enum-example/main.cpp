#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "enumexample.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<B>("Enum.Example", 1, 0, "EnumExampleB");
    qmlRegisterUncreatableType<C>("Enum.Example", 1, 0, "GadgetExample", "You can't create GadgetExample type");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    return app.exec();
}
