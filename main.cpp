#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <KWindowSystem>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // 初始化 KWin
    if (!KWindowSystem::isPlatformWayland()) {
        qWarning("This example requires a Wayland session.");
        return -1;
    }

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
