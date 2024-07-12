#include <QCoreApplication>
#include <QProcess>
#include "compositor.h"

int main(int argc, char **argv) {
    QCoreApplication app(argc, argv);

    Compositor *compositor = new Compositor();
    if (compositor->isCreated()) {
        process.start("firefox");
    }

    return app.exec();
}
