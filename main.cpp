#include <QApplication>
#include <QProcess>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // 启动Weston
    QProcess westonProcess;
    westonProcess.start("weston");

    if (!westonProcess.waitForStarted()) {
        qDebug() << "Failed to start Weston";
        return -1;
    }

    // 启动其他应用程序
    QProcess appProcess;
    appProcess.start("/usr/bin/firefox");

    if (!appProcess.waitForStarted()) {
        qDebug() << "Failed to start application";
        return -1;
    }

    return app.exec();
}
