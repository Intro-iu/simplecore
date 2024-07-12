#ifndef COMPOSITOR_H
#define COMPOSITOR_H

#include <QWaylandCompositor>

class Compositor : public QWaylandCompositor
{
    Q_OBJECT
    
public:
    Compositor();
    ~Compositor();
};

#endif // COMPOSITOR_H