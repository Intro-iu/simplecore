#include "compositor.h"
#include <QWaylandSurface>
#include <QWaylandQuickOutput>

Compositor::Compositor()
    : QWaylandCompositor()
{
}

void Compositor::create()
{
    QWaylandQuickOutput *output = new QWaylandQuickOutput(this);
    output->setGeometry(QRect(0, 0, 1920, 1080));
    output->create();
    this->create();
}
