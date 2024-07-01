#ifndef APPLICATION_H
#define APPLICATION_H

#include <QCoreApplication>
#include "process.h"

class Application : public QCoreApplication
{
    Q_OBJECT
public:
    Application(int &argc, char **argv);
    void startWaylandSession();
    void startApplication(const QString &program, const QStringList &arguments = {});

private:
    Process waylandSession;
    QList<Process*> runningProcesses;
};

#endif // APPLICATION_H
