#include <QGuiApplication>
#include <QWaylandCompositor>
#include <QWaylandQuickCompositor>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QWaylandQuickCompositor compositor;
    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("compositor", &compositor);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
