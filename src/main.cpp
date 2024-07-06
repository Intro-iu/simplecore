#include <QApplication>
#include <QPushButton>
#include <QProcess>
#include <QMessageBox>
#include <QTimer>
#include <QDebug>

void startKwinWayland() {
    QProcess *process = new QProcess;
    process->start("kwin_wayland");

    if (!process->waitForStarted()) {
        QMessageBox::critical(nullptr, "Error", "Failed to start kwin_wayland.");
        delete process;
        return;
    }

    QTimer *timer = new QTimer;
    timer->setInterval(1000); // 每秒检查一次

    QObject::connect(timer, &QTimer::timeout, [process, timer]() {
        if (process->state() == QProcess::Running) {
            qDebug() << "kwin_wayland is running.";
            QProcess::startDetached("firefox");
            QMessageBox::information(nullptr, "Success", "kwin_wayland started successfully. Now launching Firefox.");
            timer->stop();
            timer->deleteLater();
            process->deleteLater();
        } else {
            qDebug() << "Waiting for kwin_wayland to start...";
        }
    });

    timer->start();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QPushButton button("Start Wayland Session");
    QObject::connect(&button, &QPushButton::clicked, startKwinWayland);

    button.resize(200, 100);
    button.show();

    return app.exec();
}
