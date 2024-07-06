#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWaylandCompositor/QWaylandCompositor>
#include <KConfig>
#include <KConfigGroup>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QWaylandCompositor compositor;
    compositor.setOutputGeometry(QRect(0, 0, 1920, 1080));
    compositor.create();

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
