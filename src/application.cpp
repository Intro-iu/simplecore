#include "application.h"
#include <QProcessEnvironment>
#include <QThread>
#include <QTimer>
#include <QEventLoop>
#include <unistd.h> // 包含这个头文件来使用 getuid
#include <QDebug>

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
    Process *wmProcess = new Process(this);
    wmProcess->start("weston", QStringList(), env);

    if (!wmProcess->process.waitForStarted()) {
        qWarning() << "Failed to start Weston process";
        return;
    }

    if (!env.contains("WAYLAND_DISPLAY")) {
        QEventLoop waitLoop;
        m_waitLoop = &waitLoop;
        // 添加一个超时以避免在WM执行失败时无限阻塞
        QTimer::singleShot(30 * 1000, &waitLoop, SLOT(quit()));
        waitLoop.exec();
        m_waitLoop = nullptr;
    }

    runningProcesses.append(wmProcess);
}

void Application::startApplication(const QString &program, const QStringList &arguments)
{
    Process* app = new Process(this);
    app->start(program, arguments);
    runningProcesses.append(app);
}
