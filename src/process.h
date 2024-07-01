#ifndef PROCESS_H
#define PROCESS_H

#include <QObject>
#include <QProcess>

class Process : public QObject
{
    Q_OBJECT
public:
    explicit Process(QObject *parent = nullptr);
    void start(const QString &program, const QStringList &arguments, const QProcessEnvironment &env = QProcessEnvironment::systemEnvironment());
    void stop();

private:
    QProcess process;
};

#endif // PROCESS_H
