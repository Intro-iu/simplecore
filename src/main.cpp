#include <QGuiApplication>
#include <QWaylandCompositor>
#include <KWin/Wayland>

int main(int argc, char **argv) {
    QGuiApplication app(argc, argv);

    // 创建一个 Wayland 服务器
    KWin::Wayland::Server server;
    if (!server.init()) {
        qFatal("Failed to initialize Wayland server");
        return -1;
    }

    // 启动 KWin
    if (!KWin::Wayland::init()) {
        qFatal("Failed to initialize KWin Wayland");
        return -1;
    }

    // 运行事件循环
    return app.exec();
}
