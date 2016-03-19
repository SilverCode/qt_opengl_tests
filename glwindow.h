#ifndef GLWINDOW_H
#define GLWINDOW_H

#include "abstractglscene.h"
#include <QOpenGLWindow>
#include <QOpenGLFunctions>

class GLWindow : public QOpenGLWindow,
        protected QOpenGLFunctions
{
public:
    GLWindow(QWindow *parent = 0);
    void setScene(AbstractGLScene *scene) { m_scene = scene; }

protected:
    void initializeGL();
    void paintGL();

private:
    AbstractGLScene *m_scene;
};

#endif // GLWINDOW_H
