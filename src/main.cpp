#include <QApplication>
#include <QWidget>
#include <KWayland/Client/connection_thread.h>
#include <KWayland/Client/event_queue.h>
#include <KWayland/Client/registry.h>
#include <KWayland/Client/compositor.h>
#include <KWayland/Client/surface.h>

using namespace KWayland::Client;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create and connect to the Wayland server
    ConnectionThread *connection = new ConnectionThread;
    connection->setSocketName(QStringLiteral("wayland-0"));
    connection->initConnection();

    // Create an event queue and set it up with the connection
    EventQueue *queue = new EventQueue;
    queue->setup(connection);

    // Create and setup a registry
    Registry *registry = new Registry;
    registry->setEventQueue(queue);
    registry->create(connection);
    registry->setup();

    // Sync the registry
    QObject::connect(registry, &Registry::interfacesAnnounced, [&]() {
        // Check for the required interfaces here
        if (!registry->hasInterface(Registry::Interface::Compositor)) {
            qFatal("Compositor interface not available.");
        }
    });

    // Create a compositor and surface
    Compositor *compositor = registry->createCompositor(registry->interface(Registry::Interface::Compositor).name, registry->interface(Registry::Interface::Compositor).version);
    Surface *surface = compositor->createSurface();

    // Create a Qt widget to represent the window
    QWidget window;
    window.setWindowTitle("Simple Wayland Desktop");
    window.resize(800, 600);
    window.show();

    return app.exec();
}