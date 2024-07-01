#include "application.h"
#include <QProcessEnvironment>
#include <QThread>
#include <QDebug>
#include <unistd.h> // 包含这个头文件来使用 getuid

Application::Application(int &argc, char **argv)
    : QCoreApplication(argc, argv)
{
}

void Application::initEnvironment()
{
    env = QProcessEnvironment::systemEnvironment();
    env.insert("XDG_RUNTIME_DIR", QString("/run/user/%1").arg(getuid()));
    env.insert("WAYLAND_DISPLAY", "wayland-0");
}

void Application::startWindowManager()
{
    waylandSession.start("weston", QStringList(), env);

    if (!waylandSession.process.waitForStarted()) {
        qWarning() << "Failed to start Weston process";
        return;
    }

    if (!waylandSession.process.waitForReadyRead()) {
        qWarning() << "Failed to get ready read from Weston process";
        return;
    }

    qDebug() << "Weston process started successfully";
}

void Application::startApplication(const QString &program, const QStringList &arguments)
{
    Process* app = new Process(this);
    app->start(program, arguments, env);

    if (!app->process.waitForStarted()) {
        qWarning() << "Failed to start application process:" << program;
        delete app;
        return;
    }

    runningProcesses.append(app);
}
