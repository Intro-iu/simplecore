#include <QGuiApplication>
#include <QWaylandCompositor>

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    QWaylandCompositor compositor;

    compositor.create();

    if (!compositor.isCreated()) {
        qWarning("Failed to create compositor");
        return 1;
    }
    
    return app.exec();
}