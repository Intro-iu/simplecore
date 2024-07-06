#include <QApplication>
#include <QWidget>
#include <KWayland/Client/connection_thread.h>
#include <KWayland/Client/event_queue.h>
#include <KWayland/Client/registry.h>
#include <KWayland/Client/compositor.h>
#include <syslog.h>
#include <QObject>

using namespace KWayland::Client;

int main(int argc, char *argv[])
{
    // 打开syslog连接
    openlog("simple-session", LOG_PID | LOG_CONS, LOG_USER);
    syslog(LOG_INFO, "Application started");

    QApplication app(argc, argv);

    ConnectionThread connection;
    connection.initConnection();
    if (!connection.display()) {
        syslog(LOG_ERR, "Failed to connect to Wayland server");
        closelog();
        return -1;
    }
    syslog(LOG_INFO, "Connected to Wayland server");

    EventQueue queue;
    queue.setup(&connection);
    syslog(LOG_INFO, "EventQueue setup complete");

    Registry registry;
    registry.setEventQueue(&queue);
    registry.create(&connection);
    registry.setup();

    Compositor *compositor = nullptr;
    QObject::connect(&registry, &Registry::compositorAnnounced, [&](uint32_t name, uint32_t version) {
        compositor = registry.createCompositor(name, version);
    });

    if (!compositor) {
        syslog(LOG_ERR, "Failed to create compositor");
        closelog();
        return -1;
    }
    syslog(LOG_INFO, "Compositor created");

    QWidget window;
    window.setWindowTitle("Simple Wayland Desktop");
    window.resize(800, 600);
    window.show();
    syslog(LOG_INFO, "Window shown");

    int result = app.exec();
    syslog(LOG_INFO, "Application exited with code %d", result);

    // 关闭syslog连接
    closelog();

    return result;
}
