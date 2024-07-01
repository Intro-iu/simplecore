#include "application.h"

int main(int argc, char *argv[])
{
    Application app(argc, argv);

    app.startWaylandSession();
    app.startApplication("firefox");

    return app.exec();
}
