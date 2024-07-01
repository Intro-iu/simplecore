#include "application.h"

int main(int argc, char *argv[])
{
    Application app(argc, argv);

    app.initEnvironment();
    app.startWindowManager();
    app.startApplication("firefox");

    return app.exec();
}
