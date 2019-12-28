#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "screen-native-controllers/test-screen-controller/TestScreenController.h"
#include "screen-native-controllers/make-transparent-screen-controller/MakeTransparentScreenController.h"
#include "models/test-screen-models/TestScreenListModel.h"
#include "models/make-transparent-screen-model/MakeTransparentScreenModel.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("TestScreenController", new TestScreenController());
    engine.rootContext()->setContextProperty("MakeTransparentScreenController", new MakeTransparentScreenController);

    engine.rootContext()->setContextProperty("TestScreenListModel", new TestScreenListModel());
    engine.rootContext()->setContextProperty("MakeTransparentScreenModel", new MakeTransparentScreenModel());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    return app.exec();
}
