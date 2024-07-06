import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "KWin Example"

    Button {
        text: "Hello, KWin on Wayland!"
        anchors.centerIn: parent
    }
}
