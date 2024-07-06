#include <QApplication>
#include <KWayland/Client/connection_thread.h>
#include <KWayland/Client/registry.h>

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    KWayland::Client::ConnectionThread *connection = new KWayland::Client::ConnectionThread;
    connection->setSocketName("wayland-0");
    connection->initConnection();

    KWayland::Client::Registry registry;
    registry.create(connection);
    registry.setup();

    QObject::connect(connection, &KWayland::Client::ConnectionThread::connected, [&]() {
        qDebug() << "Connected to Wayland server";
    });

    return app.exec();
}
