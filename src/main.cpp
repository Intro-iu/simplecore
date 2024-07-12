#include <QGuiApplication>
#include <QWaylandCompositor>
#include <QDebug>

int main(int argc, char **argv) {
    QGuiApplication app(argc, argv);

    QWaylandCompositor *compositor = new QWaylandCompositor;

    compositor->create();

    if (!compositor->isCreated()) {
        qWarning("Failed to create compositor");
        return 1;
    }

    return app.exec();
}
