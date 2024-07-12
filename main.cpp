#include <QGuiApplication>
#include <QWaylandQuickCompositor>
#include <QDebug>

int main(int argc, char **argv) {
    QGuiApplication app(argc, argv);

    QWaylandQuickCompositor *compositor = new QWaylandQuickCompositor;

    compositor->create();

    if (!compositor->isCreated()) {
        qWarning("Failed to create compositor");
        return 1;
    }

    return app.exec();
}
