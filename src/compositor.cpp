#include "compositor.h"

Compositor::Compositor() {
    try {
        QWaylandCompositor::create();
    } catch (const std::exception &e) {
        qWarning("Failed to create compositor: %s", e.what());
    }
}

Compositor::~Compositor() {}