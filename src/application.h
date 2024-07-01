#ifndef APPLICATION_H
#define APPLICATION_H

#include <QGuiApplication>
#include "compositor.h"

class Application : public QGuiApplication
{
    Q_OBJECT
public:
    Application(int &argc, char **argv);
    void startWaylandSession();
    void startApplication(const QString &program, const QStringList &arguments = {});

private:
    Compositor compositor;
};

#endif // APPLICATION_H
