#include "compositor.h"

Compositor::Compositor() {
    QWaylandCompositor::create();
}

Compositor::~Compositor() {}