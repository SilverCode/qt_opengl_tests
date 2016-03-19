#ifndef GLWINDOW_H
#define GLWINDOW_H

#include <QOpenGLWindow>
#include <QOpenGLFunctions>

class GLWindow : public QOpenGLWindow,
        protected QOpenGLFunctions
{
public:
    GLWindow(QWindow *parent = 0);

protected:
    void initializeGL();
    void paintGL();
};

#endif // GLWINDOW_H
