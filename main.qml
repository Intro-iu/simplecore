import QtQuick 2.12
import QtWayland.Compositor 1.15

WaylandCompositor {
    id: compositor
    WaylandOutput {
        id: output
        width: 1920
        height: 1080
        scale: 1
    }
}
