#include <QApplication>
#include <QWidget>
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
        Compositor *compositor = registry.createCompositor(registry.interface(Registry::Interface::Compositor).name, registry.interface(Registry::Interface::Compositor).version);
        if (!compositor) {
            qFatal("Failed to create Wayland compositor");
            app.quit();
        }

        QWidget window;
        window.setWindowTitle("Simple Wayland Desktop");
        window.resize(800, 600);
        window.show();

        app.exec();
    });

    registry.create(connection);
    registry.setup();

    return app.exec();
}
