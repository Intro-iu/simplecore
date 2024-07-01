#ifndef APPLICATION_H
#define APPLICATION_H

#include <QCoreApplication>
#include "process.h"

class Application : public QCoreApplication
{
    Q_OBJECT
public:
    Application(int &argc, char **argv);
    void startWindowManager();
    void startApplication(const QString &program, const QStringList &arguments = {});
    void initEnvironment();

private:
    Process waylandSession;
    QList<Process*> runningProcesses;
    QProcessEnvironment env;
};

#endif // APPLICATION_H
