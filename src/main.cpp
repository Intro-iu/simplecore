#include <QApplication>
#include <QPushButton>
#include <QProcess>
#include <QMessageBox>

void startKwinWayland() {
    QProcess process;
    process.start("kwin_wayland");
    if (!process.waitForStarted()) {
        QMessageBox::critical(nullptr, "Error", "Failed to start kwin_wayland.");
        return;
    }
    QMessageBox::information(nullptr, "Success", "kwin_wayland started successfully.");
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QPushButton button("Start Wayland Session");
    QObject::connect(&button, &QPushButton::clicked, startKwinWayland);

    button.resize(200, 100);
    button.show();

    return app.exec();
}
