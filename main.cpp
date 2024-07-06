#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <KWindowSystem>
#include <QProcess>
#include <QDebug>

void startApplication(const QString &program, const QStringList &arguments = QStringList()) {
    QProcess *process = new QProcess();
    process->start(program, arguments);
    if (!process->waitForStarted()) {
        qWarning() << "Failed to start" << program << ":" << process->errorString();
    }
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // 初始化 KWin
    if (!KWindowSystem::isPlatformWayland()) {
        qWarning("This example requires a Wayland session.");
        return -1;
    }

    // 开机自启动应用程序示例
    startApplication("firefox");  // 启动浏览器

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
