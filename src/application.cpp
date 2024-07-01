#include "application.h"
#include <QProcessEnvironment>
#include <QThread>
#include <unistd.h>

Application::Application(int &argc, char **argv)
    : QCoreApplication(argc, argv)
{
}

void Application::startWaylandSession()
{
    // 设置环境变量
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("XDG_RUNTIME_DIR", QString("/run/user/%1").arg(getuid()));
    env.insert("WAYLAND_DISPLAY", "wayland-0");

    // 启动Wayland合成器，如Weston
    waylandSession.start("weston", QStringList(), env);
}

void Application::startApplication(const QString &program, const QStringList &arguments)
{
    Process* app = new Process(this);
    app->start(program, arguments);
    runningProcesses.append(app);
}
