#include <QGuiApplication>
#include "compositor.h"

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    Compositor *compositor = new Compositor();

    return app.exec();
}
