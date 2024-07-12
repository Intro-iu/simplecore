#pragma once
#include <QWaylandCompositor>
#include <QWaylandSurface>

class Compositor : public QWaylandCompositor {
    Q_OBJECT

public:
    Compositor() {
        create();
    }

protected:
    void create() override;
};
