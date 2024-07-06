import QtQuick 2.15
import QtQuick.Window 2.15
import QtWayland.Compositor 1.15

WaylandCompositor {
    id: compositor
    width: 1920
    height: 1080
    visible: true

    ShellSurfaceItem {
        anchors.fill: parent
    }
}
