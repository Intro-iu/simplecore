#include <QApplication>
#include <QWidget>
#include <QDebug>
#include <KWayland/Client/connection_thread.h>
#include <KWayland/Client/event_queue.h>
#include <KWayland/Client/registry.h>
#include <KWayland/Client/compositor.h>

using namespace KWayland::Client;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create and setup the Wayland connection
    auto connection = ConnectionThread::fromApplication();
    if (!connection) {
        qFatal("Failed to create Wayland connection");
        return -1;
    }

    EventQueue queue;
    queue.setup(connection);

    Registry registry;
    QObject::connect(&registry, &Registry::interfacesAnnounced, [&]() {
        auto interfaces = registry.interfaces();
        bool compositorFound = false;
        quint32 compositorName = 0;
        quint32 compositorVersion = 0;

        for (const auto &interface : interfaces) {
            if (interface.name == "wl_compositor") {
                compositorFound = true;
                compositorName = interface.name;
                compositorVersion = interface.version;
                break;
            }
        }

        if (!compositorFound) {
            qFatal("Compositor interface is not valid");
            app.quit();
        }

        Compositor *compositor = registry.createCompositor(compositorName, compositorVersion);
        if (!compositor) {
            qFatal("Failed to create Wayland compositor");
            app.quit();
        }

        QWidget window;
        window.setWindowTitle("Simple Wayland Desktop");
        window.resize(800, 600);
        window.show();

        qDebug() << "Wayland connection and compositor created successfully.";
    });

    registry.create(connection);
    registry.setup();

    return app.exec();
}
