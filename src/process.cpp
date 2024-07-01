#include "process.h"

Process::Process(QObject *parent) : QObject(parent)
{
}

void Process::start(const QString &program, const QStringList &arguments, const QProcessEnvironment &env)
{
    process.setProcessEnvironment(env);
    process.start(program, arguments);
}

void Process::stop()
{
    process.kill();
}
