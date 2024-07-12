#include <QGuiApplication>
#include <QWaylandCompositor>
#include <QDebug>

class Compositor : public QWaylandCompositor
{
    Q_OBJECT
public:
    Compositor() {
        create();
    }
};

int main(int argc, char **argv) {
    QGuiApplication app(argc, argv);

    Compositor compositor;

    compositor.create();

    if (!compositor.isCreated()) {
        qWarning("Failed to create compositor");
        return 1;
    }

    return app.exec();
}
