#ifndef COMPOSITOR_H
#define COMPOSITOR_H

#include <QWaylandCompositor>

class Compositor : public QWaylandCompositor
{
    Q_OBJECT
public:
    Compositor();
    void create();
};

#endif // COMPOSITOR_H
