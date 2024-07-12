#include <QGuiApplication>
#include "compositor.h"

int main(int argc, char **argv) {
    QGuiApplication app(argc, argv);

    Compositor *compositor = new Compositor();
    if (!compositor->isCreated()) {
        qWarning("Failed to create compositor");
        return 1;
    }

    return app.exec();
}
