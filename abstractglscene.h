#ifndef ABSTRACTGLSCENE_H
#define ABSTRACTGLSCENE_H

#include <QOpenGLFunctions>
#include <QOpenGLWindow>

class AbstractGLScene : protected QOpenGLFunctions
{
public:
    AbstractGLScene(QOpenGLWindow *window = 0);
    virtual ~AbstractGLScene() {}

    QOpenGLWindow* window() const { return m_window; }

    QOpenGLContext* context() {
        return window() ? window()->context() : 0;
    }

    const QOpenGLContext* context() const {
        return window() ? window()->context() : 0;
    }

    virtual void paint() = 0;
    virtual void initialize();

private:
    QOpenGLWindow *m_window = NULL;
};

#endif // ABSTRACTGLSCENE_H
