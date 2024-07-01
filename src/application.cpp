#include "application.h"
#include <QProcess>
#include <QProcessEnvironment>
#include <unistd.h>

Application::Application(int &argc, char **argv)
    : QGuiApplication(argc, argv)
{
}

void Application::startWaylandSession()
{
    // 初始化Wayland合成器
    compositor.create();
}

void Application::startApplication(const QString &program, const QStringList &arguments)
{
    QProcess *appProcess = new QProcess(this);
    appProcess->start(program, arguments);
}
